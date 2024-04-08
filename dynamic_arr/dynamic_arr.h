#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

typedef struct dynamic_arr
{
	void** dt_arr;
	uint64_t max_capacity;
	uint64_t elements;
	
	void (*destroy_fn)(void*);                        // function for freeing the data provided by user
	bool (*comparision_fn)(const void*, const void*); // returns true if data passed in first parameter is greater 
													  // than second, otherwise returns false
}	dynamic_arr;

dynamic_arr* initDynamicArr(uint64_t init_size, void (*destroy_fn)(void*), void (*comparision_fn)(const void*, const void*));

static void resize(dynamic_arr* arr);

static bool hasSpace(dynamic_arr* arr);           // true if max capacity not exceeded, else false

void pushBack(dynamic_arr* arr, const void* element);

const void* pop_back(dynamic_arr* arr);

void setElement(dynamic_arr* arr, uint64_t index, const void* element);

const void* getElement(dynamic_arr* arr, uint64_t index);

const void* peekFirst(dynamic_arr* arr); 

const void* peekLast(dynamic_arr* arr);

void clearArray(dynamic_arr* arr, void (*destroy_fn)(void*));

const void* containsElement(dynamic_arr* arr, const void* element);

#endif