#include <iostream>
#include <bitset>
#include <sstream>

#pragma region Binary Conversion

/*! \Function This will be used to convert a number passed into its binary form.
Param One: Int - The number needing to be cnverted.
*/
std::string l_ConvertToBinary(int numberToConvert)
{
	// This will be used to convert the passed integer into its binary representation. 
	std::string l_sBinaryOutput = std::bitset<8>(numberToConvert).to_string();

	// This will flip the string allowing for it to be read better inside the console. 
	std::reverse(l_sBinaryOutput.begin(), l_sBinaryOutput.end());

	return l_sBinaryOutput;
}

#pragma endregion

#pragma region Baum Sweet Examination

/*! \Function This will be used to examine the first 4 components of a binary sequnce entered into this 
*				function. It will then look for a pair of two consecutive 0s if the pair is found this 
*				funtion will return a 1 otherwise will return a 0. 
* Param One: String - The binary value which will be checked by the function. 
*/
int l_BinaryExamination(std::string binaryValueToCheck)
{

	// Local Variables \\

	/*! \var The value to be returned at the end of this function. */
	int l_iReturnValue = 1; 

	/*! \var The value previously checked by the for-loop it will be updated at the 
	*			end of said loop. It will be used to loop for a pair of consecutive 
	*			0s. 
	*/
	int l_iPreveousValue = -1; 

	/*! \var This will be used to count the number of consecutive 0s allowing for the 
		*		program to detect if there are either a even or odd number of 0s. 
		*/
	int l_iNumberOfZeros = 0;

	/*! \var Used to limit the number of binary spaces to check depending upon how 
		*		far the first 1 is located within the set. 
		*/
	int l_iNumberOfSpacesToCheck = 1;

	// Algorithm Start \\

	// This will loop from the back of the binary set to find the first occurence of 1. 
	for (int j = binaryValueToCheck.size(); j > 0; j--)
	{
		if (binaryValueToCheck[j] == '1')
		{
			l_iNumberOfSpacesToCheck += j;
		}
	}
	 
	// Debugging \\ 
	std::cout << "\nOnly Checking :" << l_iNumberOfSpacesToCheck << std::endl;

	// Start of for loop, and will only last for the first 4 parts of the binary set. 
	for (int i = 0; i < l_iNumberOfSpacesToCheck; i++)
	{
		// Debugging \\ 
		std::cout << "\nNumber Being Checked " << binaryValueToCheck[i] << std::endl;

		// Using the current place in the binary set this will check if the value is eithr 1 or 0
		// enabling the progra to count the number of 0s in a row. 
		switch (binaryValueToCheck[i])
		{
		// Should only trigger on first round of for loop. 
		case '-1': 
			
			// Debugging \\ 
			std::cout << "\nStarting The Checks ... \n";

			break; 

		// If the previous value is a zero this case will be entered, This will be used to check 
		// and see if both the previous and current is 0 allowing for the sequnce to be mapped.
		case '0':

			l_iNumberOfZeros++; 	
			
			break; 

		// If the preveous value is 0 than the sequence is already broken and thus will return a 0; 
		case '1': 

			// Debugging \\ 
			std::cout << "\nCurrent Number of 0s : " << l_iNumberOfZeros << std::endl;;
				
			if (l_iNumberOfZeros % 2 > 0)
			{
				// Debugging \\ 
				std::cout << "Uneven number of 0s detected.\n";

				l_iReturnValue = 0;
			}

			l_iNumberOfZeros = 0; 
		
			break;

		// Used for debugging, if anything goes wrong this will trigger. 
		default:

			// Debugging \\ 
			std::cout << "Unexpected Value detected : " + l_iPreveousValue; 

			break;
		}

		// Characters in C++ starts at 48 so minusing 48 from the character value 
		// should reduce it's value to its integer value for example the character
		// for '1' would have an integer value of 49 so to get back to 1 would be 
		// '1' - 48 and so on. 
		l_iPreveousValue = binaryValueToCheck[i] - 48;
	}

	// Debugging \\ 
	std::cout << "Return Value : " << l_iReturnValue << std::endl;

	return l_iReturnValue; 
}

#pragma endregion

#pragma region Sequence Construction

/*! \Function This will be used to build the sequence to a number of steps provided into this function. 
*				It will skip over 0 for continuity. 
* Param One: Int - The number of steps the function will work to, and will determine the length of the 
*					final output. 
*/
std::string l_BuildingSequence(int numberOfLoops)
{
	/*! \var The value being outputted by this function. */
	std::string l_iReturnValue; 

	// Using the number of loops variable will create the Baum Sweet sequence to the specified number. 
	for (int i = 1; i <= numberOfLoops; i++)
	{

		/*! \var The current binary set being checked.*/
		std::string l_sCurrentBinaryNumber = l_ConvertToBinary(i); 

		/*! \var This will be used to convert the return type of the binary examination function from an 
		*			Integer into a Character enabling it to be added into the final product String.
		*/
		std::stringstream l_ssCharConverter; 

		/*! \var This will simply be a container for the final product from the binary examination function 
		*			so it can be added into the final product string allowing it to be returned into main. 
		*/
		std::string l_sNewProduct; 

		// Debugging \\ 
		std::cout << "\nStarting the examination of number : " << i << std::endl;

		// Binary Processing 
		l_ssCharConverter << l_BinaryExamination(l_sCurrentBinaryNumber); ; 

		// Type Conversion
		l_ssCharConverter >> l_sNewProduct; 

		l_iReturnValue += l_sNewProduct; 
	}

	// Debugging \\ 
	std::cout << l_iReturnValue << std::endl;

	return l_iReturnValue; 
}

#pragma endregion

#pragma region Procedual Main Function 

int main()
{
	// Local Variables

	/*! \var This will be used to convert the value inputted by the user into an integer value 
	*			usable by the algorithm. 
	*/
	std::stringstream l_ssIntConverter; 

	/*! \var This will hold the data the user enters into the program, a number of spaces in the 
	*			Baum Sweet sequence.
	*/
	std::string l_sInput; 

	/*! \var The final product outputted by the program, a list of numbers following the Baum Sweet 
	*			sequence.
	*/
	std::string l_sFinalOutput; 

	/*! \var A number of spaces the player has inputted for use by the program, will determine the 
	*			final length of the sequence. 
	*/
	int l_iLoopInput; 

	// Entry Text. 

	// Debugging \\ 
	std::cout << "Welcome to the Baum Sweet sequence constructor, \n\nEnter a number and I will create a sequence of numbers where a pair of 00s will display a 1 and everything else will display a 0." << std::endl; 

	// Debugging \\ 
	std::cout << "\n Please Enter Your Number Here: ";

	// Text Conversion.

	std::cin >> l_sInput; 

	l_ssIntConverter << l_sInput; 

	l_ssIntConverter >> l_iLoopInput; 

	// Back end processing. 

	l_sFinalOutput = l_BuildingSequence(l_iLoopInput);

	// Ending Output 

	std::cout << "\n" << l_sFinalOutput << std::endl;

}

#pragma endregion
