#include <stdio.h>
#include <stdlib.h>

//when this program is executed it will use the command " ./fileswap INPUTFILENAME noOfRows noOfColumns OUTPUTFILENAME "
//for example, " ./fileswap mat.in 10 5 mat.out "

int main(int argc, char *argv[])
{
	if(argc == 5 && fopen(argv[1],"r")) //This checks whether there are 5 arguments in the command line. Argc returns the number of inputs, including the executable name.
	{
		FILE *fpr; //create file pointer for reading (i did this for clarity, you could re-use the same pointer if you wanted to)
		fpr = fopen(argv[1],"r"); //assign the reading pointer to the file given as the argument argv[1] in the command line (mat.in)
		FILE *fpw; //create file pointer for writing (see above)
		fpw = fopen(argv[4],"w"); //assign the writing pointer to the file given as the argument argv[4] in the command line (mat.out)
		
		int i,j = 0; //create some iterators for nested FOR loops
		int newCol = atoi(argv[2]); //here I create variables to store the new number of columns and rows as the opposite of the input.
		int newRow = atoi(argv[3]); //the goal of the program is to swap each column for a row and vice versa
									//i could have just directly addressed atoi(argv[2]) each time but i prefer making variables

		int *arr[newRow]; //create an array with a size corresponding to the number of rows in the output
						  //this might not work out of the box. some people report crashes with this, so you might have to create a dynamic array instead
		for(i=0;i<newRow;i++) //for each row in the output
		{
			arr[i] = (int*)malloc(newCol * sizeof(int)); //create a dynamic array (2nd dimension!) for each row
		}
		printf("Array created with %d rows and %d columns.\n",newRow,newCol); //this was for debugging but is handy to verify you've made the right size
		
		for(i = 0;i<newCol;i++) //for each column in the output
		{
			for(j=0;j<newRow;j++) //for each row in each column (basically we iterate through the entire array we created)
			{
				char buffer[4]; //how many characters to read with each fgets. for the given input file, we need 4 bits.
				fgets(buffer,4,fpr); //read 4 bits into the input buffer we just declared using the fpr
				printf("%s added to Array at row %d column %d.\n",buffer,j,i); //debugging print but handy to track any irregularities
				arr[j][i] = atoi(buffer); //put the read information in the array as an int using atoi()
			}	
		}
		//we have now finished reading in information! here would be where you re-allocate the pointer if you wanted to re-use it.
		//now we move on to writing the data into the new file, but in the new format.
		//for example, the input file 1, 2, 3, 4
		//							  5, 6, 7, 8
		//would become:
		//							  1, 5
		//							  2, 6
		//							  3, 7
		//							  4, 8

		//hopefully that makes sense!

		for(i=0;i<newRow;i++) //again, for each ROW (reversed from the read)
		{
			for(j=0;j<newCol;j++) //for each COLUMN in each row (reversed from the read)
			{
				fprintf(fpw," %d ",arr[i][j]); //write the character surrounded by spaces into the file
			}
			fprintf(fpw,"\n"); //after each row is complete, type a newline character
		}
	}
	else //finally, if the user got the number of arguments wrong (aka, the wrong command line thing) then we can just tell them and do nothing else.
	{
		printf("Incorrect number of arguments. Please try again.\n");
	}	
			
}
