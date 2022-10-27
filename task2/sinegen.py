import math
import string
f = open("sinerom.mem","w")

# take 256 samples of cos
for i in range(256):
    v = int(math.cos(2*3.1416*i/256)*127+127) # we shift and scale the range to fit with 0-255 
    # i.e. 1 becomes 255 and -1 becomes 0

    if (i+1)%16 == 0: # if the output is 16th, we start a new line
        s = "{hex:2X}\n" # format into 2 digit hex
    else:
        s = "{hex:2X} "
    f.write(s.format(hex=v))

f.close()