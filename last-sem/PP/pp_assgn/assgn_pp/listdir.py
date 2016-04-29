import os

path_name="/home/AAP_FINAL"

for (path_name,dirname,file_name) in os.walk(path_name):

print path_name
print dirname
print file_name


