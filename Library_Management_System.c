#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,n;

void get_details();
void issue_book();
void return_book();
void search_book();
void display_book();

struct books{
    char book_name[30];
    char author_name[30];
    int year;
    int copies;
};

struct books lib[100];

int main(){
    
    int choice;
    printf("------------LIBRARY MANAGEMENT SYSTEM-------------\n\n");
    
    while(1){
        
        printf("1. Get book details\n2. To issue a book\n3. To return a book\n4. To search a book\n\n");
        
        printf("Enter the choice : ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: get_details(lib);
                    break;
                    
            case 2: issue_book(lib);
                    break;
            
            case 3: return_book(lib);
                    break;
            
            case 4: search_book(lib);
                    break;
            
			case 5: display_book(lib);
					break;
					
            case 6: exit(0);
            
            default: printf("Enter a valid choice\n");
        }
    }
}

void get_details(struct books lib[100]){
    
    printf("\nEnter no of books to be entered : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("\n\nEnter books name : ");
        scanf("%s", lib[i].book_name);
        printf("Enter author name : ");
        scanf("%s", lib[i].author_name);
        printf("Enter the year of publication : ");
        scanf("%d" , &lib[i].year);
        printf("Enter total no of copies : ");
        scanf("%d" , &lib[i].copies);
    }
}

void issue_book(struct books lib[100]){
    char title[30];
    printf("\nEnter the book title : ");
    scanf("%s",title);
    
    for(i=0;i<n;i++){
        if(strcmp(lib[i].book_name,title)==0){
            if(lib[i].copies<=0){
                printf("\nBook Unavailable\n");
                lib[i].copies=0;
            }
            else{
                lib[i].copies--;
                printf("\nNo of Copies Remaining : %d\n", lib[i].copies);
            }
        }
    }
}

void return_book(struct books lib[100]){
    
    char title[30];
    printf("\nEnter the book title : ");
    scanf("%s",title);
    
    for(i=0;i<n;i++){
        
        if(strcmp(lib[i].book_name,title)==0){
            ++lib[i].copies;
            printf("\nNo of Copies Remaining : %d\n",lib[i].copies);
            break;
        }
    }
}

void search_book(struct books lib[100]){
    int yr;
    printf("\nEnter the year of publishment of book : ");
    scanf("%d",&yr);
    
    for(i=0;i<n;i++){
        if(lib[i].year==yr){
            printf("\n%s\t%s\t%d\t%d\n",lib[i].book_name,lib[i].author_name,lib[i].year,lib[i].copies);
            break;
        }
    }
}

void display_book(struct books lib[100]){
    printf("\nBooks List\n");
    for(i=0;i<n;i++){
        printf("\n%s\t%s\t%d\t%d\n",lib[i].book_name,lib[i].author_name,lib[i].year,lib[i].copies);
    }
}