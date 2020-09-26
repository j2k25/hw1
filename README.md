# CG_hw1

OS: Windows 10;

IDE: NotePad++ and command line g++ through MinGW;

C:\> ./g++ hw1.cpp -o hw1

C:\> ./hw1


Thank you for giving us the reading and a basic assignment. I struggled
to use the given algorithm and gave up at the last minute even though I 
was continually progressing, albeit slowly. 

I instead implemented the (R cos@, R sin@) method. With every 360 cycle,
variation causes a sideways shift in pixel selection that served to 
extend my line with many cycle passes.

There was an arifact persitently present in my outfile image after being 
converted online to a jpg. This artifact was interesting in itself. 
It appeared throughout all three converted outputs the different programs I
worked on for this assignment (One, was the standard book algorithm from the 
reading. Two, was this origin-theta based algorythm I submitted here as hw1. 
Three, was an algorithm based on using y = +/- sqrt(R^2 - x^2) and complex 
numbers, but I couldn't find the coding methods to do it.)

Although they were all different, they all contained the same 32bit binary 
number 1000111010101010101010100110011 with another 0 at either the beginning
or end. Interestingly, if you place the 0 in the beginning, the resulting 
number is close to the number of bytes the image uses in storage. The placement 
and effect of the artifact was reminiscent of watermarking copies. 

