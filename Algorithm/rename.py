import re
import os

ls = os.listdir()

for _ in ls:
    if os.path.isdir(_):
        files = os.listdir(_)
        for file in files:
            src = _ + '\\' + file
            dst = _ + '\\' + re.sub(r'\s+', '_', file)
            os.rename(src, dst)
    os.rename(_, re.sub(r'\s+', '_', _))