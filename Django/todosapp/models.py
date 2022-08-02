from django.db import models

# Create your models here.
from django.db import models
from django.utils import timezone

class Todo(models.Model):
	date=models.DateTimeField(default=timezone.now)
	title=models.CharField(max_length=100)
	details=models.TextField()
	

	def __str__(self):
		return self.title

