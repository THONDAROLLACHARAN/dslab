#include<stdio.h>
#include<string.h>
#define SIZE 10
#define EMPTY -1
typedef struct
{
	int key;
	char value[50];
}
DictEntry;
DictEntry table[SIZE];
int hash(int key)
{
	return key % SIZE;
	
}
void init()
{
	int i=0;
	for(i=0;i=SIZE;i++)
	{
		table[i].key = EMPTY;
	}
}
void insert(int key, char value[])
{
int index = hash(key);

while (table[index].key != EMPTY)
{
index = (index + 1) % SIZE; 
}

table[index].key = key; 
strcpy(table[index].value, value); 
}
char*search(int key)
{
int index = hash(key);
int i=0;
for(i = 0; i < SIZE; i++)
{
if (table[index].key == key)
return table[index].value;
index = (index + 1) % SIZE;
}
return NULL;
}
int main()
{
	init();
	
	insert(101,"VJIT");
	insert(102,"CBIT");
	insert(103,"MGIT");
	
	char* result=search(103);
    if (result !=NULL)
	printf("Value = %\n",result);
   else
	printf("Key not found\n");
	
	return 0;
}
