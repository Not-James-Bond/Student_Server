# Generated by Django 2.2.4 on 2019-11-01 23:46

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('myapp1', '0003_auto_20191102_0511'),
    ]

    operations = [
        migrations.AddField(
            model_name='project',
            name='project_bio',
            field=models.CharField(default=2, max_length=2000),
            preserve_default=False,
        ),
    ]
