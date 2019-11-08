from random import *
from django.contrib.auth import authenticate
from django.shortcuts import render,HttpResponseRedirect,redirect
from django.contrib import auth
from django.contrib.messages import success,error
from django.db.models import Q
from django.contrib.auth.decorators import login_required
from .models import *
from .forms import *
from django.core.mail import send_mail
from django.conf import settings
from django.core.files.storage import FileSystemStorage
from django.http import HttpResponseNotFound,HttpResponse
from django.views.generic import CreateView,DetailView,TemplateView
from django.core.paginator import Paginator , EmptyPage , PageNotAnInteger
from django.core.files.base import ContentFile
import re
from cryptography.fernet import Fernet
import base64
import logging
import traceback


def Home(request):
    language = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    return render(request,"index.html",{"Study": study,"Language": language,"Project_Language": project_l,})

    '''DATABASE'''


def semester(request,cn):
    lang = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    stud = Study.objects.get(sname=cn)
    sem = Semester.objects.filter(semcat__sname__contains=cn)
    return render(request, "sem.html",{"Semester":sem,"Studyone":stud,"Study": study,"Language": lang,"Project_Language": project_l,})


def subjects(request,cn,semids):
    lang = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    stud = Study.objects.get(sname=cn)
    sem = Semester.objects.filter(semcat__sname__contains=cn).order_by('semname')
    sub = Subject.objects.filter(subsemester__semname__contains=semids,subsemester__semcat__sname__contains=cn)
    semone = Semester.objects.get(semname=semids)

    return render(request, "subject.html",{"Study": study,"Studyone": stud,"Semester":sem,"Subject":sub,"Semesteroneobject":semone,"Language": lang,"Project_Language": project_l,})

'''
def units(request,cn,semids,subs):
    stud = Study.objects.get(sname=cn)
    sems = Semester.objects.get(semname=semids)
    sub = Subject.objects.filter(subsemester__semcat__sname__contains=cn)
    unn = Unit.objects.filter(usub__subname__contains=subs)
    subone = Subject.objects.get(subname=subs)
    return render(request,"units.html",{"Study":stud,"Semester":sems,"Subject":sub,"Unit":unn,"Subjectone":subone})
'''


def filess(request,cn,semids,subs):
    lang = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    stud = Study.objects.get(sname=cn)
    sems = Semester.objects.filter(semcat__sname__contains=cn)
    semone = Semester.objects.get(semname=semids)
    sub = Subject.objects.filter(subsemester__semcat__sname__contains=cn,subsemester__semname__contains=semids)
    file = File.objects.filter(subfile__subname__contains=subs)
    subone = Subject.objects.get(subname=subs)
    return render(request,"files.html",{"Study":study,"Semester":sems,"Subject":sub,"File":file,"Subjectone":subone,
                                        "Studyone": stud,"Semesteroneobject": semone,"Language": lang,
                                        "Project_Language": project_l,})



def fileprogram(request, pfile):
    fp = FileSystemStorage(location='media/Program')
    filename = pfile
    if fp.exists(filename):
        with fp.open(filename, 'rb') as pdf:
            response = HttpResponse(pdf, content_type='application/pdf')
            response['Content-Disposition'] = 'inline; filename = file'
            return response
    else:
        return HttpResponseNotFound('file not found')


def single_project(request,projectone):
    language = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    single_pro = Project.objects.get(project_name=projectone)
    comment_img = Profile.objects.all()
    if request.method == 'POST':
        user = User.objects.all()
        comment = comment_for_project()
        comment.comment_body = request.POST.get('comment')
        comment.comment_user = request.POST.get('name')
        comment.comment_for_project_name = projectone
        comment.save()
        user_who_tagged = request.POST.get('name')
        comment_content = request.POST.get('comment')
        test = comment_content.split()
        check = '@'
        res = [idx for idx in test if idx[0].lower() == check.lower()]
        tag_users = [w.replace('@', '') for w in res]
        if tag_users:
            for i in tag_users:
                for j in user:
                    if j.username == str(i):
                        notify = Notification()
                        notify.notify_user = j.username
                        notify.notification_name = user_who_tagged + " mentioned you in a comment"
                        notify.notification_link = '/project_details/'+ projectone + "/"
                        notify.save()

        redirect('/project_details/'+projectone +'/')
    comments = comment_for_project.objects.filter(comment_for_project_name__contains=projectone)

    return render(request,'single-project.html',{"Comments":comments,"Study": study,"Language": language,
                                                 "Project_Language": project_l,"Profile_img":comment_img,
                                                 "Projectone": single_pro})


def project_file(request,project_file):
    fp = FileSystemStorage(location='media/project_files')
    filename = project_file
    if fp.exists(filename):
        with fp.open(filename, 'rb') as pdf:
            response = HttpResponse(pdf, content_type='application/pdf')
            response['Content-Disposition'] = 'attachment; filename = file'
            return response
    else:
        return HttpResponseNotFound('file not found')




    '''DATABASE ENDS'''


def login(request):
    if request.method == 'POST':
        uname = request.POST.get('uname')
        pward = request.POST.get('pward')

        user = auth.authenticate(username=uname, password=pward)
        if user is not None:
            auth.login(request, user)
            if user.is_superuser:
                return HttpResponseRedirect('/admin')
            else:
                return HttpResponseRedirect('/')
        else:
            error(request, "Invalid User")
    return render(request,'login.html')

'''
def signup(request):
    
    if request.method == 'POST':
        form = ExtenUserCreationForm(request.POST)
        profile_form = UserProfileForm(request.POST)
        if form.is_valid() and profile_form.is_valid():
            user = form.save()
            profile = profile_form.save(commit=False)
            profile.user = user
            profile.save()
            username = form.cleaned_data.get('username')
            password = form.cleaned_data.get('password')
            users = authenticate(username=username,password=password)
            login(request , users)
            return redirect('/')

    else:
        form = ExtenUserCreationForm()
        profile_form = UserProfileForm()

    return render(request,'signup.html',{'Form':form,'pform':profile_form})

'''


def signup(request):
    if request.method == 'POST':
        uname = request.POST.get('uname')
        try:
            match = User.objects.get(username=uname)
            if match:
                error(request,"UserName already Exist")
        except:
            fname=request.POST.get('first_name')
            lname = request.POST.get('last_name')
            email = request.POST.get('email')
            pward = request.POST.get('pass')
            cpward = request.POST.get('cpa')
            mobno= request.POST.get('mobno')
            ages = request.POST.get('age')
            if pward == cpward:
                otp = str(int(99999 * random()))
                subject = 'Thank you for registering to our site'
                message = ' your code is: ' + otp
                '''
                email_from = settings.EMAIL_HOST_USER
                recipient_list = ['devilritik30@gmail.com', ]
                send_mail(subject, message, email_from, recipient_list)
                '''
                otp = encrypt(otp)
                return HttpResponseRedirect('/otp/' + email + '/' + fname + '/' + lname + '/' + pward + '/' + mobno +
                                            '/' + ages + '/' + uname + '/' + otp)
                '''function call to other function which is related to otp confirmation'''
                '''
                User.objects.create_user(username=uname,
                                            first_name=fname,
                                            last_name=lname,
                                            email=email,
                                            password=pward)
                use = User.objects.all()
                for u in use:
                    if u.username == uname:
                        data = Profile()
                        userr = request.POST.get('uname')
                        ct = User.objects.get(username=userr)
                        data.user = ct
                        data.mobile_no = mobno
                        data.age = ages
                        data.save()

                return HttpResponseRedirect('/login/')
                success(request, "Account is created")
                '''
            else:
                error(request,"Password & Confirm Password not Matched")
    return render(request,'signup.html')


def encrypt(txt):
    try:
        cipher_suite = Fernet(settings.ENCRYPT_KEY)
        emcrypted_text = cipher_suite.encrypt(txt.encode('ascii'))
        encrypted_text = base64.urlsafe_b64encode(emcrypted_text).decode("ascii")
        return encrypted_text
    except Exception as e:
        logging.getLogger("error_logger").error(traceback.format_exc())
        return None


def decrypt(txt):
    try:
        txt = base64.urlsafe_b64decode(txt)
        cipher_suite = Fernet(settings.ENCRYPT_KEY)
        decoded_text = cipher_suite.decrypt(txt).decode('ascii')
        return decoded_text
    except Exception as e:
        logging.getLogger("error_logger").error(traceback.format_exc())
        return None


def view_dash_from_outside(request,uname):
    profile = Profile.objects.all()
    for i in profile:
        if i.user.username == uname:
            profile_image = i.user_image
            profile_bio = i.bio
            profile_username = i.user.username
            profile_first_name = i.user.first_name
            profile_last_name = i.user.last_name
            content = {"p_img":profile_image,"p_bio":profile_bio,"p_user:":profile_username,"p_fname":profile_first_name
                       ,"p_lname":profile_last_name}
    return render(request,"view_dashboard_from_outside.html",content)



def logout(request,uname):
    auth.logout(request)
    return HttpResponseRedirect('/')
    

def about(request):
    return render(request,'about.html')


def ask_us(request):
    language = Computer_Language.objects.all()
    project_l = Project_Language.objects.all()
    study = Study.objects.all()
    if request.method == 'POST':
        ask = Ask_us()
        ask.question = request.POST.get('question')
        ask.question_Explain = request.POST.get('explain_question')
        ask.person = request.POST.get('person_name')
        ask.email = request.POST.get('person_email')
        ask.save()
        success(request,"Your question is recorded :) We will mail you")
    return render(request,"ask_us.html",{"Study": study,"Language": language,"Project_Language": project_l,})


def coursepdf(request,files):
    fs = FileSystemStorage()
    fp = FileSystemStorage(location='media/')
    filename = files
    if fs.exists(filename):
        with fs.open(filename,'rb') as pdf:
            response = HttpResponse(pdf,content_type='application/pdf')
            response['Content-Disposition'] = 'attachment; filename = file'
            return response
    else:
        return HttpResponseNotFound('file not found')


'''Pagination'''


def program(request,cn):
    lang = Computer_Language.objects.all()
    langone = Computer_Language.objects.get(l_name=cn)
    stud = Study.objects.all()
    project_all = Project_Language.objects.all()
    prog = Computer_Program.objects.filter(program_language__l_name__contains=cn)
    page = request.GET.get('page', 1)
    paginator = Paginator(prog, 9)
    try:
        prog = paginator.page(page)
    except PageNotAnInteger:
        prog = paginator.page(1)
    except EmptyPage:
        prog = paginator.page(paginator.num_pages)
    return render(request, "program.html", {"Study": stud, "Language": lang,"Languageone": langone,"Programname": prog,
                                            "Project_Language": project_all,})


def project(request,prolan):
    study = Study.objects.all()
    language = Computer_Language.objects.all()
    project_all = Project_Language.objects.all()
    project_lanone = Project_Language.objects.get(pl_name=prolan)
    projectss = Project.objects.filter(project_language__pl_name__contains=prolan)
    page = request.GET.get('page',1)
    paginator = Paginator(projectss,3)
    try:
        pro = paginator.page(page)
    except PageNotAnInteger:
        pro = paginator.page(1)
    except EmptyPage:
        pro = paginator.page(paginator.num_pages)
    return render(request,'project.html',{'proj':pro,"Project_lanone":project_lanone,
                                           "Project_Language": project_all,
                                           "Study": study,"Language": language,})


def email_verification(request, email, fname, lname, pward, mobno , ages, uname,otp):
    otp = decrypt(otp)
    if request.method == 'POST':
        password = request.POST.get('pass')
        if password == otp:
            User.objects.create_user(username=uname,
                                     first_name=fname,
                                     last_name=lname,
                                     email=email,
                                     password=pward)
            use = User.objects.all()
            for u in use:
                if u.username == uname:
                    data = Profile()
                    userr = uname
                    ct = User.objects.get(username=userr)
                    data.user = ct
                    data.mobile_no = mobno
                    data.age = ages
                    data.save()

            success(request,email)
            return redirect('/')
            success(request, "Account is created")
        else:
            error(request,"Wrong otp")
    else:
        error(request,otp)
    return render(request,"OTP.html",{"Otp":otp})


@login_required(login_url='/login/')
def profileview(request,uname):
    users = Profile.objects.get(user__username__contains=uname)
    notify = Notification.objects.filter(notify_user__contains=uname)
    if request.method == 'POST':
        users.facebook = request.POST.get('facebook')
        users.twitter = request.POST.get('twitter')
        users.github = request.POST.get('github')
        users.bio = request.POST.get('bio')
        img = request.FILES.get('uimage')
        if img:
            users.user_image = img
        users.save()

    return render(request,"user.html",{"User":users,'Notify':notify})


@login_required(login_url='/login/')
def accountview(request,uname):
    use = User.objects.get(username__contains=uname)
    users = Profile.objects.get(user__username__contains=uname)
    if request.method =='POST':
        new_username = request.POST.get('new_username')
        confirm_username = request.POST.get('confirm_new_username')
        current_username = request.POST.get('current_username')
        new_mobile = request.POST.get('new_mobile')
        confirm_mobile = request.POST.get('confirm_new_mobile')
        current_mobile = request.POST.get('current_mobile')

        if new_username == confirm_username and current_username == users.user.username:
            alluser = User.objects.all()
            user_not_exist = True
            for i in alluser:
                if new_username == i.username:
                    user_not_exist = False

            if user_not_exist:
                use.username = new_username
                use.save()
                users.user.username = new_username
                users.save()
                success(request, "Saved")
            else:
                error(request,"user already exist")



        else:
            error(request,"username already exist")

        if new_mobile == confirm_mobile and current_mobile == users.mobile_no:
            users.mobile_no = new_mobile
        else:
            error(request,"please correct mobile number")

        users.save()

    return render(request,"account.html",{"User":users})


@login_required(login_url='/login/')
def dashboard(request,uname):
    user = Profile.objects.get(user__username__contains=uname)
    return render(request,"dashboard.html",{"User": user})

