
#include "DynamicTable.h"

void DynamicTable::insert(int value, bool dummy_version) {
	
    //add a new element in the table
    //use `dummy_version` to decide which version of resize you want to call
    
    //array needs resize because there is not space for the insert
    if(last == size){
    	if(dummy_version == true)
    		resize_dummy();
    	else
    		resize();
    }
    //place the object in the array
  	table[last] = value;
  	last += 1;

}

void DynamicTable::resize_dummy() {

    //resize the table when necessary adding one empty spot
		//create new array one cell larger
		int newSize = size + 1;
		int * newTab = new int[newSize];

		//copy contents over to new array
		for(int i = 0; i < size; i++){
			newTab[i] = table[i];
		}

		//get rid of old table and replace it with the new
		size = newSize;
		delete[] table;
		table = newTab;
}

void DynamicTable::resize() {

    //resize the table when necessary doubling its size
		//create new array 2 times larger
		int newSize = size * 2;
		int * newTab = new int[newSize];

		//copy contents over to new array
		for(int i = 0; i < size; i++){
			newTab[i] = table[i];
		}

		//get rid of old table and replace it with the new
		size = newSize;
		delete[] table;
		table = newTab;

}






