#include<stdio.h>
#include<string.h>

typedef struct Book
{
    char name[100];
    int code;
}Bk;


void AddBook(Bk *s,int code);
void actions(char ch, char chh, int oldcode);
void showallbooks();
void searchbook();
void Addnew(int code);


int main()
{
    int n;
    printf("enter total no. of books in your library : ");
    scanf("%d", &n);
    getchar();
    int bookcode=0;

    Bk book[n];

    FILE *fptr;
    fptr = fopen("data.txt","w");

    for (int i=0;i<n;i++){
        bookcode++;
        AddBook(&book[i],bookcode);
        fprintf(fptr,"%d \n",book[i].code);
        fprintf(fptr,"%s \n",book[i].name);
        
    }

    fclose(fptr);


    char c;
    char cs;
    actions(c,cs,bookcode);
    
    
    return 0;
}

//adding a book by taking a input from user 
void AddBook(Bk *s,int code){
    
    printf("enter book name: ");
    fgets(s->name,100,stdin);
    size_t len=strlen(s->name);
    if(len>0 && s->name[len-1]=='\n'){
        s->name[len-1]='\0';
    }
    s->code=code;
}

// performing actions
void actions(char ch,char chh,int oldcode){
    printf("Do u want to know what you can do in this program ? \n type 'Y' for yes and 'N' for no");
    scanf("%c", &ch);
    getchar();//newline clrd
    if(ch=='Y'){
        printf("can SHOW ALL BOOKS \n can SEARCH A BOOK NAME BY CODE \n");
        printf("What action would u like to do? \n options are \n A)show all books \n B)search a book name by code \n C) Add a new book \n");
        scanf("%c", &chh);
        if(chh=='A'){
            showallbooks();

        }else if(chh=='B'){
            searchbook();
        }else if(chh=='C'){
            Addnew(oldcode);
        }else {
            printf("no such action is designed");
            return;
        }

    }else if(ch == 'N'){
        return;
    } else {
        printf("Sorry we cant do that operation");
        return;

    }
}


//showing all books
void showallbooks(){
    FILE *fptr;
    char line[200];

    fptr = fopen("data.txt","r");
    if (fptr == NULL){
        printf("error opening file \n");
    }
    printf("Books in Library: \n \n");
    while (fgets(line,sizeof(line),fptr)){
        printf("%s",line);
    }
    fclose(fptr);
}

//searching a book by its code assigned
void searchbook(){
    int search;
    printf("enter code of the book");
    scanf("%d",&search);

    FILE *fptr;
    fptr = fopen("data.txt","r");
    if(fptr == NULL){
        printf("error opening file \n");
        return;
    }
    int code;
    char name[100];
    int found;

    while (fscanf(fptr,"%d \n",&code)==1)
    {
        fgets(name, sizeof(name),fptr);
        
        size_t len= strlen(name);
        if(len > 0 && name[len-1]=='\n'){
            name[len-1] ='\0';
        }
        if(code == search) {
            printf("book found : %s \n", name);
            found = 1;
            break;
        }   
    }
    if (!found){
        printf("book with the given code not found");
    }

    fclose(fptr);
    
}

void Addnew(int code){
    int n;
    printf("enter how much books u need to store ");
    scanf("%d",&n);
    getchar();

    int bkc=code;
    int n_= n+code;
    Bk book[n_];

    FILE *fptr;
    fptr = fopen("data.txt","a");

    for (int i=code;i<(n_);i++){
        bkc++;
        AddBook(&book[i],bkc);
        fprintf(fptr,"%d \n",book[i].code);
        fprintf(fptr,"%s \n",book[i].name);
        
    }
    fclose(fptr);


}
