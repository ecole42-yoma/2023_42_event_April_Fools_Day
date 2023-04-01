#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		char temp = argv[i][0];
		if (temp != '.')
		{
			std::cout << temp;
		}
	}
	std::cout << std::endl;
}

// 1.
// 2.
// 3.
// 4.  CONGRATULATIONS ON DECODING THIS LINE THE NEXT CHARACTER IS 2
// 5.  CONGRATULATIONS ON DECODING THIS LINE THE NEXT LETTER IS J
// 6.  Congratulations on decoding this line the next letter is F
// 7.
