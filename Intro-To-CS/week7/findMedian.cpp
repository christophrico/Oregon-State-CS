/***********************************************************
** Author: Christopher Rico
** Date: 5/17/17
** Description: This function returns the median of an array that is 
   passed to it 
************************************************************/

   #include <iostream>
   #include <algorithm>

   //function to find the median. Takes an array and the # of elements
   //as arguments, and returns a double.
   double findMedian(int arr1[], int arrSize)
   {
   		double median;
		
		//sort the array in ascending order
   		std::sort(arr1, arr1 + arrSize);
		
		// case if the array has an even number of ints
   		if(arrSize % 2 == 0)
   		{
			//the average of the two middle ints
			median = (static_cast<double>(arr1[(arrSize/2)-1] + arr1[arrSize/2]) / 2);
   		}

		// case if the array has an odd number of ints
   		else
   		{
			//special case if the array just has one int
   			if(arrSize == 1)
			{
				median = arr1[arrSize-1];
			}
			
			// then the median is the int in the very middle
			else
			{
				median = arr1[(arrSize/2)];
   			}
		}
   		
		return median;
   }


/*
   int main()
   {
   		int testArr[1] = {2};
		int testArr2[4] = {2,10,5,1}; 
   		int testArr3[7] = {5,2,17,0,3,10,1}; 
		int testArr4[6] = {-7, 12 , 9, 17, -2, 6};

   			std::cout << findMedian(testArr, 1) << std::endl;
   			std::cout << findMedian(testArr2, 4) << std::endl;
   			std::cout << findMedian(testArr3, 7) << std::endl;
   			std::cout << findMedian(testArr4, 6) << std::endl;

   		return 0;
 
   }
*/
