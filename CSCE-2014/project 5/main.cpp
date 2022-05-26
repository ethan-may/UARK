//------------------------------------------------------------------
// Author:  Ethan May
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include "timer.h"

//------------------------------------------------------------------
// Check to see if data is sorted correctly
//------------------------------------------------------------------
bool data_sorted(int data[], int count)
{
   // Put specified count of random numbers into data array
   for (int index = 1; index < count; index++)
      if (data[index-1] > data[index])
         return false;
   return true;
}

//------------------------------------------------------------------
// Check to see if data is sorted correctly
//------------------------------------------------------------------
bool data_sorted_reverse(int data[], int count)
{
   // Put specified count of random numbers into data array
   for (int index = 1; index < count; index++)
      if (data[index-1] < data[index])
         return false;
   return true;
}

//------------------------------------------------------------------
// Initialize data array with random values
//------------------------------------------------------------------
void create_random_data(int data[], int count, int range)
{
   // Put random data values into array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

//------------------------------------------------------------------
// Initialize data array with mostly sorted values
//------------------------------------------------------------------
void create_mostly_sorted_data(int data[], int count, int swaps)
{
   // Put sorted data values into array
   for (int index = 0; index < count; index++)
      data[index] = index;

   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < swaps; index++)
   {
      int pos1 = rand() % count;
      int pos2 = rand() % count;
      int temp = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}

//------------------------------------------------------------------
// Read input file to initialize data array
//------------------------------------------------------------------
void read_data(string name, int data[], int &count, int &range)
{
   // Open input file
   ifstream din;
   din.open(name.c_str());
   if (din.fail())
      cout << "Error: could not open input file\n";

   // Read the data
   range = 0;
   din >> count;
   for (int i = 0; i < count; i++)
   {
      din >> data[i];
      if (data[i] > range)
	 range = data[i];
   }

   // Close the file
   din.close();
   range++;
}

//------------------------------------------------------------------
// Write data array to output file
//------------------------------------------------------------------
void write_data(string name, int data[], int count)
{
   // Open output file
   ofstream dout;
   dout.open(name.c_str());
   if (dout.fail())
      cout << "Error: could not open output file\n";

   // Write the data
   dout << count;
   for (int i = 0; i < count; i++)
   {
      if (i % 20 == 0)
	 dout << endl;
      dout << data[i] << " ";
   }

   // Close the file 
   dout.close();
}

//------------------------------------------------------------------
// CLASSIC BINARY Mergesort implementation with copy array
//------------------------------------------------------------------
void cb_merge_sort2(int data[], int copy1[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      cb_merge_sort2(data, copy1, low, mid);
      cb_merge_sort2(data, copy1, mid + 1, high);

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	 if (data[index1] < data[index2])
	    copy1[index++] = data[index1++];
	 else
	    copy1[index++] = data[index2++];
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
	 copy1[index++] = data[index1++];

      // Copy any remaining entries from the second half
      while (index2 <= high)
	 copy1[index++] = data[index2++];

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	 data[low + index] = copy1[index];
   }
}

//------------------------------------------------------------------
// CLASSIC BINARY Mergesort implementation without copy array
//------------------------------------------------------------------
void cb_merge_sort(int data[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Allocate memory and call merge_sort2
      int *copy1 = new int[range];
      cb_merge_sort2(data, copy1, low, high);
      delete[]copy1;
   }
}

//------------------------------------------------------------------
// THREE WAY Mergesort implementation
//------------------------------------------------------------------
void merge_3way(int sort[], int copy[], int low, int t1, int t2, int high)
{
    int index1 = low; 
    int index2 = t1; 
    int index3 = t2; 
    int index = low; 
    
    // Merge largest data elements into copy array -----------------------------
    while ((index1 < t1) && (index2 < t2) && (index3 < high))
    {
        if (sort[index1] > sort[index2])
        {
            if (sort[index1] > sort[index3])
            {
                copy[index++] = sort[index1++];
            }
            else
            {
                copy[index++] = sort[index3++];
            }
        }
        else
        {
            if (sort[index2] > sort[index3])
            {
                copy[index++] = sort[index2++];
            }
            else 
            {
                copy[index++] = sort[index3++];
            }
        }
    }
    // ------------------------------------
    while ((index1 < t1) && (index2 < t2))
    {
        if (sort[index1] > sort[index2])
        {
            copy[index++] = sort[index1++];
        }
        else 
        {
            copy[index++] = sort[index2++];
        }
    }
    // -------------------------------------
    while ((index2 < t2) && (index3 < high))
    {
        if (sort[index2] > sort[index3])
        {
            copy[index++] = sort[index2++];
        }
        else 
        {
            copy[index++] = sort[index3++];
        }
    }
    // -------------------------------------
    while ((index1 < t1) && (index3 < high))
    {
        if (sort[index1] > sort[index3])
        {
            copy[index++] = sort[index1++];
        }
        else 
        {
            copy[index++] = sort[index3++];
        }
    }
    
    // Copy any remaining elements from each third -----------------------------
    while (index1 < t1)
    {
        copy[index++] = sort[index1++];
    }
    // -------------------------------------
    while (index2 < t2)
    {
        copy[index++] = sort[index2++];
    }
    // -------------------------------------
    while (index3 < high)
    {
        copy[index++] = sort[index3++];
    }
}

//------------------------------------------------------------------
// THREE WAY Mergesort implementation 
//------------------------------------------------------------------
void merge_3way_sort(int sort[], int copy[], int low, int high)
{
   // Check terminating condition
   if ((high - low) < 2)
   {
       return;
   }
   
   // Divide the array into thirds and sort
   int t1 = low + ((high - low) / 3);
   int t2 = low + 2 * ((high - low) / 3) + 1;
   merge_3way_sort(copy, sort, low, t1);
   merge_3way_sort(copy, sort, t1, t2);
   merge_3way_sort(copy, sort, t2, high);
   
   // Starting merging the sorted thirds together
   merge_3way(copy, sort, low, t1, t2, high);
}

//------------------------------------------------------------------
// THREE WAY Mergesort implementation 
//------------------------------------------------------------------
void merge_3way_start(int sort[], int count) 
{
   int temp[count];
   for (int index = 0; index < count; index++)
   {
       temp[index] = sort[index];
   }
   
   // Starting the recursive merge function calls
   merge_3way_sort(temp, sort, 0, count);
   
   for (int index = 0; index < count; index++)
   {
       sort[index] = temp[index];
   }
}

//------------------------------------------------------------------
// main program to test sorting functions
//------------------------------------------------------------------
int main()
{
   const int MAX_COUNT = 1000000;
   const int MAX_RANGE = 1000000;
   int data[MAX_COUNT];
   
   // Print sorting method menu
   cout << "Select sorting method:\n"
        << "  b - use classic binary merge sort\n"
        << "  t - use 3-way merge sort\n"
        << "Enter Command: ";

   // Perform requested sort
   char choice;
   cin >> choice;

   // Prompt user for sort parameters
   cout << "\nEnter number of data values [1.." << MAX_COUNT << "]: ";
   int count;
   cin >> count;
   if (count > MAX_COUNT)
      count = MAX_COUNT;

   cout << "Enter range of data values [1.." << MAX_RANGE << "]: ";
   int range;
   cin >> range;
   if (range > MAX_RANGE)
      range = MAX_RANGE;
   
   // Create input data
   create_random_data(data, count, range);
   
   // Write original random data into new text file
   write_data("sort.in", data, count);

   // Takes the users input and starts the merge
   Timer t;
   t.start_timer();
   switch (choice)
   {
   case 'b':
      cb_merge_sort(data, 0, count - 1);
      break;
   case 't':
      merge_3way_start(data, count);
      break;
   }
   t.end_timer();
   cout << "\nCPU time = " << t.elapsed_cpu() << " sec\n";
 
   // Write output file
   write_data("sort.out", data, count);

   // Check data is sorted
   if (choice == 'b')
   {
       if (!data_sorted(data, count)) 
       {
           cout << "ERROR: Data not sorted correctly!\n";
       }
   }
   else if (choice == 't')
   {
       if (!data_sorted_reverse(data, count)) 
       {
           cout << "ERROR: Data not sorted correctly!\n";
       }
   }
}
