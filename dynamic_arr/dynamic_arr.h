#ifndef VECTOR
#define VECTOR

typedef enum errVectors
{
	VECTOR_INIT_FAIL,
	VECTOR_RESIZE_FAIL,
};

typedef struct dynamic_arr
{
	void** arr;
	uint64_t max_capacity;
	uint64_t elements;
	
	void (*destroy_fn)(void*);                        // function for freeing the data provided by user
	bool (*comparision_fn)(const void*, const void*); // returns true if data passed in first parameter is greater than second
}	vector;


#endif