#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CONTACT 100
#define NAME_LEN 50
#define PHONE_LEN 10
#define EMAIL_LEN 20
struct Contact
{
    char name[NAME_LEN];
    int phone[PHONE_LEN];
    char email[EMAIL_LEN];
};
struct Contact addressBook[MAX_CONTACT];
int count=0;
void trimNewline(char *str){
    str[strcspn(str,"\n")]=0;
}
void addContacts(){
    if(count>=MAX_CONTACT){
        printf("address book is done..ho gya full\n");
        return;
    }
    struct Contact NewContact;
    printf("enter the name..\n");
    getchar();
    fgets(NewContact.name,NAME_LEN,stdin);
    trimNewline(NewContact.name);
    printf("enter the phone no..\n");
    fgets(NewContact.phone,PHONE_LEN,stdin);
    trimNewline(NewContact.phone);
    printf("enter the email..\n");
    fgets(NewContact.email,EMAIL_LEN,stdin);
    trimNewline(NewContact.email);
    addressBook[count++]=NewContact;
    printf("contact added successfully!!\n");
}
void displayContacts(){
    if(count==0){
        printf("No contact found.\n");
        return;
    }
    printf("\n----CONTACT LIST-----\n");
    for(int i=0;i<count;i++){
        printf("[%d]NAME:%s\n",i+1,addressBook[i].name);
        printf("Phone:%s\n",addressBook[i].phone);
        printf("Email:%s\n",addressBook[i].email);
        printf("--------------\n");
    }
}
void searchContacts(){
    char query[50];
    int found=0;
    printf("Enter the name to search:");
    getchar();
    fgets(query,sizeof(query),stdin);
    query[strcspn(query,"\n")]=0;
    for (int i=0;i<count;i++){
        if(strcmp(addressBook[i].name,query)==0){
            printf("\nContact Found:\n");
            printf("Name: %s\n",addressBook[i].name);
            printf("Phone:%s\n",addressBook[i].phone);
            printf("Email:%s\n",addressBook[i].email);
            found=1;
            break;
        }
    }
    if (!found){
        printf("contact not found.\n");
    }
}
void deleteContacts(){
    char query[50];
    int found=-1;
    printf("enter name to delete:");
    getchar();
    fgets(query,sizeof(query),stdin);
    query[strcspn(query,"\n")]=0;
    for(int i=0;i<count;i++){
        if(strcmp(addressBook[i].name,query)==0){
            found=i;
            break;
        }
    }
    for(int i=found;i<count-1;i++){
        addressBook[i]=addressBook[i+1];
    }
    count--;
    printf("contact deleted successfully!!\n");
}


int main() {
    int choice;

    while (1) {
        printf("\nAddress Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                addContacts();
                break;
            case 2:
                deleteContacts();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}