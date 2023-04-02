#include <cctype>
#include <cstdlib>
#include <iostream>

void decode_(std::string msg, int key)
{
	for (int i = 0; i < msg.size(); i++)
	{
		if (!std::isalpha(msg[i]))
			continue;
		msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
	}
	std::cout << "\nkey : " << key << "\n" << msg << std::endl;
}

void decode__(std::string msg, int key)
{
	for (int i = 0; i < msg.size(); i++)
	{
		if (!std::isalpha(msg[i]))
			continue;
		msg[i] = (msg[i] - 'A' - key) % 26 + 'A';
	}
	std::cout << "\nkey : -" << key << "\n" << msg << std::endl;
}

int main(int argc, char **argv)
{
	// std::string msg = "veh jxyi unuhsysu oek mybb xqlu je mhyju jxu fqiimeht
	// " 				  "yd q iocrebkc.jnj vybu";

	std::string msg = "RSOEBLNZAYNDQOT QT IKITREUM OEBO YEUM, NKG AYTN PGSZNMB "
					  "RT : K ";

	for (int i = 1; i < 27; i++)
	{
		decode_(msg, i);
	}
	for (int i = 1; i < 27; i++)
	{
		decode__(msg, i);
	}
	std::cout << std::endl;
}

// 1. For this exercice you will have to write the password in a symbolum.txt
// file. // caesar cipher 16

// 2. Congratulations on decoding this line, the first letter is: k //base64

// 3. Congratulations on decoding this line, the third letter is: h //alphabetical substitution

// 4. CONGRATULATIONS ON DECODING THIS LINE THE NEXT CHARACTER IS 2 // unicode decimal

// 5.  CONGRATULATIONS ON DECODING THIS LINE THE NEXT LETTER IS J //spelling alphabet, nato alphabet

// 6.  Congratulations on decoding this line the next letter is F // LEET speak

// 7. may be H or
// pebyklufpyuvcbbcgfggfowhg
