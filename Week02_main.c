#include <stdio.h>
#include <string.h>
#include "Week02_LinkedList.h"

// 자유롭게 함수 테스트 하는 공간입니다.
void test_free(void)
{

}

void test_list(void)
{
	DoublyLinkedList test_list;
	bool bool_result = true; 
	int int_result = 0;

	printf("1\n");
	list_init(&test_list);
	printf("2\n");
	bool_result = is_empty_list(&test_list);
	printf("3\n");
	
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	bool_result = is_full_list(&test_list);
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	char name[NAME_ARRAY_SIZE] = "";
	int id = 0;

	// insert_head

	strcpy_s(name, NAME_ARRAY_SIZE, "김민석");
	id = 2021084884;
	insert_tail(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "김재민");
	id = 2021050300;
	insert_tail(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "최민준");
	id = 2021050300;
	insert_tail(&test_list, name, id);
	print_list(&test_list);
	
	search_name(&test_list, 2021084884);
	search_id(&test_list, "김재민");
	search_id(&test_list, "최민준");
}

int main(void)
{
	test_free();
	test_list();

	return 0;
}