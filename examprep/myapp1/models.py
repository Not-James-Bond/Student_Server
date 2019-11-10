from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    mobile_no = models.CharField(max_length=12,blank=True)
    age = models.CharField(max_length=12, blank=True)
    bio = models.CharField(max_length=150, blank=True)
    facebook = models.CharField(max_length=100, blank=True)
    github = models.CharField(max_length=100, blank=True)
    twitter = models.CharField(max_length=100, blank=True)
    user_image = models.ImageField(upload_to='Userpics',blank=True,default='Userpics/none/face-1.jpg')

    def __str__(self):
        return self.user.username


class Study(models.Model):

    sid = models.AutoField
    sname = models.CharField(max_length=10)

    def __str__(self):
        return self.sname


class Semester(models.Model):
    semid = models.AutoField
    semcat = models.ForeignKey(Study, on_delete=models.CASCADE)
    semname = models.CharField(max_length=20)

    def __str__(self):
        return self.semname


class Subject(models.Model):
    subid = models.AutoField
    subname = models.CharField(max_length=20)
    subsemester = models.ForeignKey(Semester,on_delete=models.CASCADE)

    def __str__(self):
        return self.subname


class Unit(models.Model):
    uid = models.AutoField
    usub = models.ForeignKey(Subject, on_delete=models.CASCADE)
    uname = models.CharField(max_length=60)

    def __str__(self):
        return self.uname


class File(models.Model):
    fid = models.AutoField
    subfile = models.ForeignKey(Subject, on_delete=models.CASCADE)
    fname = models.CharField(max_length=25)
    files = models.FileField(upload_to='ebook',blank=True)
    img1 = models.ImageField(upload_to='ebook/img',blank=True)

    def __str__(self):
        return self.fname

'''
class Language(models.Model):
    lid = models.AutoField
    lname = models.CharField(max_length=20)

    def __str__(self):
        return self.lname


class Program(models.Model):
    pid = models.AutoField
    pname = models.CharField(max_length=150)
    programlanguage = models.ForeignKey(Language,on_delete=models.CASCADE)
    program_file = models.FileField(upload_to='Program',blank=True)

    def __str__(self):
        return self.pname
'''


class Computer_Language(models.Model):
    l_id = models.AutoField
    l_name = models.CharField(max_length=20)

    def __str__(self):
        return self.l_name


class Computer_Program(models.Model):
    p_id = models.AutoField
    p_name = models.CharField(max_length=150)
    program_language = models.ForeignKey(Computer_Language,on_delete=models.CASCADE)
    program_files = models.FileField(upload_to='Program',blank=True)

    def __str__(self):
        return self.p_name


class Project_Language(models.Model):
    pl_id = models.AutoField
    pl_name = models.CharField(max_length=20)

    def __str__(self):
        return self.pl_name


class Project(models.Model):
    project_id = models.AutoField
    project_name = models.CharField(max_length=100)
    project_language = models.ForeignKey(Project_Language,on_delete=models.CASCADE)
    project_bio = models.CharField(max_length=2000,blank=True)
    project_image = models.ImageField(upload_to='project_images',blank=True)
    project_output_1 = models.ImageField(upload_to='project_images',blank=True)
    project_output_2 = models.ImageField(upload_to='project_images',blank=True)
    project_File = models.FileField(upload_to='project_files',blank=True)

    def __str__(self):
        return self.project_name


class Ask_us(models.Model):
    ask_us_id = models.AutoField
    question = models.CharField(max_length=150)
    question_Explain = models.CharField(max_length=400)
    person = models.CharField(max_length=40)
    email = models.EmailField()

    def __str__(self):
        return self.person


class comment_for_project(models.Model):
    comment_id = models.AutoField
    comment_body = models.CharField(max_length=90000)
    comment_user = models.CharField(max_length=50,blank=True)
    comment_for_project_name = models.CharField(max_length=75)

    def __str__(self):
        return self.comment_user


class Notification(models.Model):
    notifications = models.AutoField
    notify_user = models.CharField(max_length=60,blank=True)
    notification_link = models.CharField(max_length=300)
    notification_name = models.CharField(max_length=100)

    def __str__(self):
        return self.notification_name
