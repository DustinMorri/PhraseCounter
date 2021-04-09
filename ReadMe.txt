This is a simple phrase counter.
It can help you figure out which words and phrases appear the most frequently in a text.
If you use it, please tell me about it at dustin.morri@gmail.com so that I can brag about it in interviews.
For quick use on Windows:
	Download phraseCount.exe.
	Put it in the same folder as the file you want it to work on.
	Open that folder in command prompt.
	Pipe it in and run it with:
		phraseCount 2 4 < in.txt > out.txt
		The 2 here can be replaced with any number less than the second number as long as it's greater than or equal to 1.
		It is the minimum number of words in a phrase.
		The 4 here can be replace with any number.
		It is the maximum number of words in a phrase.
		It may take some time to process if you want a really high maximum, but it's rare that 5 or more of the same words appear in the same order multiple times except in modern pop songs.
		So, it's not even worth putting this number above 5.
There is also a simple stop word filterer included.
It's written in Perl because I was feeling hacky.
If you have Perl installed you can take in the output from phraseCount and get only the phrases not containing a stop word.
To get this:
	phraseCount 2 4 < in.txt | perl stopWordFilter.pl > out.txt
