#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

typedef struct 
{
    char phone[15];
    char name[20];
    char address[50];
} UserInfo;

// 散列表节点结构体
typedef struct 
{
    char phone[15];
    UserInfo *user;
} HashNode;

// 散列表结构体
typedef struct 
{
    HashNode *nodes[TABLE_SIZE];
} HashTable;


int hashFunction1(const char *phone) 
{
    int sum = 0;
    for (int i = 0; i < strlen(phone); i++) {
        sum += (int)phone[i];
    }
    return sum % TABLE_SIZE;
}
// 哈希函数2：电话号码长度
int hashFunction2(const char *phone) 
{
    return strlen(phone) % TABLE_SIZE;
}
// 初始化散列表
HashTable* initializeHashTable() 
{
    HashTable *hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        hashTable->nodes[i] = NULL;
    }
    return hashTable;
}
void insert(HashTable *hashTable, const char *phone, const char *name, const char *address) {
    UserInfo *user = (UserInfo*)malloc(sizeof(UserInfo));
    strncpy(user->phone, phone, sizeof(user->phone));
    strncpy(user->name, name, sizeof(user->name));
    strncpy(user->address, address, sizeof(user->address));
    int index = hashFunction1(phone); 

    if (hashTable->nodes[index] == NULL) 
	{
        HashNode *node = (HashNode*)malloc(sizeof(HashNode));
        strncpy(node->phone, phone, sizeof(node->phone));
        node->user = user;
        hashTable->nodes[index] = node;
    } 
		else 
	{
        printf("Collision occurred at index %d\n", index);
    }
}

UserInfo* find(HashTable *hashTable, const char *phone) {
    int index = hashFunction1(phone); 

    
    if (hashTable->nodes[index] != NULL && strcmp(hashTable->nodes[index]->phone, phone) == 0) {
        return hashTable->nodes[index]->user;
    } else {
        printf("Record not found for phone number %s\n", phone);
        return NULL;
    }
}

void print(HashTable *hashTable) 
{
    for (int i = 0; i < TABLE_SIZE; i++) {
    	
        if (hashTable->nodes[i] != NULL) 
		{
            printf("Index %d: Phone: %s, Name: %s, Address: %s\n", i, hashTable->nodes[i]->phone,
                   hashTable->nodes[i]->user->name, hashTable->nodes[i]->user->address);
        }
    }
}

int main() {
    HashTable *hashTable = initializeHashTable();
    
    insert(hashTable, "1234567890", "小明", "123 aa");
    insert(hashTable, "0987654321", "小红", "456 bb");
    insert(hashTable, "1111111111", "小刘", "789 cc");
    insert(hashTable, "2222222222", "小王", "987 dd");
    insert(hashTable, "3333333333", "小张", "654 ee");
    
    print(hashTable);
    
    UserInfo *user = find(hashTable, "0987654321");
    if (user != NULL) {
        printf("Record found: Phone: %s, Name: %s, Address: %s\n", user->phone, user->name, user->address);
    }
    
    return 0;
}
