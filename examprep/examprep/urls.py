from myapp1 import views as my
from django.contrib import admin
from django.urls import path,include
from django.contrib.staticfiles.urls import static
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from . import settings

urlpatterns = [
    path('admin/', admin.site.urls),
    path('',my.Home),
    path('sem/<str:cn>/',my.semester),
    path('sub/<str:cn>/<str:semids>/', my.subjects),
    path('un/<str:cn>/<str:semids>/<str:subs>/', my.filess),
    path('lan/<str:cn>/', my.program),
    path('Program/<str:pfile>/', my.fileprogram),
    path('prolan/<str:prolan>/', my.project),
    path('login/', my.login),
    path('filename/<str:files>/', my.coursepdf),
    path('signup/', my.signup),
    path('logout/<str:uname>', my.logout),
    path('about/',my.about),
    path('ask_us/',my.ask_us),
    path('otp/<str:email>/<str:fname>/<str:lname>/<str:pward>/<str:mobno>/<str:ages>/<str:uname>/<str:otp>/',my.email_verification),
    path('project_details/<str:projectone>/',my.single_project),
    path('profileview/<str:uname>',my.profileview),
    path('account/<str:uname>',my.accountview),
    path('dashboard/<str:uname>',my.dashboard),
    path('view_dashboard_from_outside/<str:uname>',my.view_dash_from_outside),
    path('project_files/<str:project_file>',my.project_file),
]

urlpatterns = urlpatterns+staticfiles_urlpatterns()
urlpatterns = urlpatterns+static(settings.MEDIA_URL,
                                 document_root=settings.MEDIA_ROOT)
