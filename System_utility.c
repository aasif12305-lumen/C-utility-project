#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Student{
    char name[50];
    int age;
    float mark;
};

void createFile(void);
void viewFile(void);
void appendFile(void);

void saveStudent(struct Student students[],int studentCount){
    FILE *filename=fopen("student.txt","w");
    if(filename==NULL){
        printf("Save failed\n");
        return;
    }
    else{
        for(int i=0;i<studentCount;i++){
            fprintf(filename,"%s,%d,%.1f\n",students[i].name,students[i].age,students[i].mark);
            
    }printf("Saved\n");
    fclose(filename);
    }
    
}

void addStudents(struct Student students[],int *studentCount){
    if(*studentCount>=10)
    {
        printf("Students limit reached");
        return;
    }
    
    int check=1;
    const char *error="name";
    while(check==1){
        int validName=1;
        printf("Enter name=");
    if(fgets(students[*studentCount].name,sizeof(students[*studentCount].name),stdin)){
        students[*studentCount].name[strcspn(students[*studentCount].name,"\n")]='\0';
        if (students[*studentCount].name[0] == '\0') {
        validName = 0;
    }

        for(int i=0;students[*studentCount].name[i] !='\0';i++){
            int result=isalpha((unsigned char)students[*studentCount].name[i]);
            if(result==0 &&  students[*studentCount].name[i] != ' '){
                validName=0;
                break;
            }
        }
            if(validName!=0){
               error="age";
        printf("Enter age=");
         if(scanf("%d",&students[*studentCount].age)==1 && students[*studentCount].age >0){
             error="mark";
            printf("Enter mark=");
             if( scanf("%f",&students[*studentCount].mark)==1 && ((0<=students[*studentCount].mark) && ((students[*studentCount].mark)<=100))){
                (*studentCount)++;
            saveStudent(students,*studentCount);
            
            check=0;
             }   
             else{
                 int ch;
                  while((ch=getchar()) !='\n' && ch !=EOF){
            
        }
                 printf("%s is invalid!",error);
             }    
         }  else{
                int ch;
                while((ch=getchar()) !='\n' && ch !=EOF){
            
                }
                printf("%s is invalid!",error);
                 }   
    }
    else{
        
        printf("%s is invalid!\n",error);
    } 
            }
        }
         
    }
    
    
    


void viewStudents(struct Student students[],int studentCount){
    if(studentCount==0){
        printf("No students is added");
    }
    else{
        printf("====STUDENTS DATA====\n");
    for(int i=0;i<studentCount;i++){
         printf("Student Name=%s\n",students[i].name);
         printf("Student Age=%d\n",students[i].age);
         printf("Student Mark=%.1f\n",students[i].mark);

    }
    }
}

void convertLower(char name[]){
         for(int i=0;name[i] != '\0';i++)
             name[i]=(char)tolower((unsigned char)name[i]);
           
}

int search(struct Student students[],int studentCount,char searchName[]){
   int index; 
   char lstoredName[50];
   for(index=0;index<(studentCount);index++){
                    int j;
                for(j=0;students[index].name[j] != '\0';j++){
                    lstoredName[j]=(char)tolower((unsigned char)students[index].name[j]);
                }
                lstoredName[j]='\0';

                if(strcmp(searchName,lstoredName)==0){
                return index;
         }

         }
            return -1; 
}


void searchStudents(struct Student students[],int studentCount){
         char searchName[50];
                if(studentCount!=0){ printf("Enter the name to search=");
               fgets(searchName,sizeof(searchName),stdin); 
               searchName[strcspn(searchName,"\n")]='\0';
                convertLower(searchName);
              int result= search(students,studentCount,searchName);
           if(result!=-1){
               printf("Name=%s",students[result].name);
               printf("Age=%d",students[result].age);
               printf("Mark=%.1f",students[result].mark);
           }
           else{
            printf("Name not found\n");
           }        }else{
            printf("There is no records stored\n");
           }
               
}

void updateStudent(struct Student students[],int studentCount){
       char updatename[50];
       int updateAge;
       float updateMark;
       if (studentCount == 0) {
    printf("No student records available\n");
    return;
}
       printf("Enter the name to update=");
       fgets(updatename,sizeof(updatename),stdin);
       updatename[strcspn(updatename,"\n")]='\0';
       convertLower(updatename);
       int index=search(students,studentCount,updatename);
       if(index!=-1){
        int error=0;
        int error2=0;
        while(error==0){
            printf("Enter the age=");
        if(scanf("%d",&updateAge)==1 && updateAge>0){
            error=1;
            while(error2==0){
                printf("Enter the mark=");
                            if(scanf("%f",&updateMark)==1 && ((updateMark>=0) && (updateMark<=100))){
                                students[index].age=updateAge;
                                students[index].mark=updateMark;
                                    saveStudent(students,studentCount);
                                    error2=1;
            }
             else{
                int clear;
        while((clear=getchar()) != '\n' && clear!=EOF){

        }
                printf("Mark is invalid\n");
             }  
            }
        }
       else{
           printf("Age is invalid\n");
        int clear;
        while((clear=getchar()) != '\n' && clear!=EOF){

        }
       }
      
       }
       }else{
        printf("Name not found!\n");
       }
        
}

void deleteStudent(struct Student students[],int *studentCount){
       char delName[50];
       if (*studentCount == 0) {
    printf("No student records available\n");
    return;
}
       printf("Enter the name to delete=");
      fgets(delName,sizeof(delName),stdin);
      delName[strcspn(delName,"\n")]='\0';
       convertLower(delName);
      int index=search(students,*studentCount,delName);
      if(index!=-1){
        for(index;index<*studentCount-1;index++){
        students[index]=students[index+1];
       
    }printf("Deleted\n");
    (*studentCount)--;
      saveStudent(students,*studentCount);
      }
      else printf("Name not found!\n");
    
}

void studentsRecords(struct Student students[],int *studentCount){
    int choice;
    do{
    printf("====STUDENT RECORDS====\n");
    printf("1.Add Students\n");
    printf("2.View Students\n");
    printf("3.Search Students\n");
    printf("4.Update Students\n");
    printf("5.Delete Students\n");
    printf("6.Back\n");
    printf("Enter the choice=");
  if(scanf("%d",&choice)!=1){
    int ch;
     while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    printf("Ivalid value\n");
    continue;
  }
    int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {
}
    switch (choice)
    {
    case 1:
        addStudents(students,studentCount);
        break;
    
    case 2:
        viewStudents(students,*studentCount);
        break;
    case 3:
        searchStudents(students,*studentCount);
        break;
    case 4:
        updateStudent(students,*studentCount);
        break;
    case 5:
        deleteStudent(students,studentCount);
        break;
    case 6:
        return;
    default:
        printf("Invalid Choice\n");
        break;
    }
    }while (choice!=6);
    
    
}

void fileManager(){
    int choice;
    do{printf("====FILE MANAGER====\n");
    printf("1.Create/Write File.\n");
    printf("2.View File.\n");
    printf("3.Append to File.\n");
    printf("4.Back to Main Menu.\n");
    printf("Enter the choice\n");
    if(scanf("%d",&choice)!=1){
        printf("Invalid value\n");
        int ch;
        while((ch=getchar())=='\n' && ch!=EOF){
        }
        choice=0;
        continue;   
    }
    int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {
}
    switch(choice){
        case 1:
           createFile();
           break;
        case 2:
           viewFile();
           break;
        case 3:
           appendFile();
           break;
        case 4:
           return;
        default:
           printf("Invalid Choice");
           break;
    }}while(choice!=4);
    
}

float high_mark(struct Student students[],int studentCount){
   int i=1;
   float highest=students[0].mark;

   for(i;i<studentCount;i++){
    if(highest<students[i].mark){
        highest=students[i].mark;
    }
   }
   return highest;
}

float average_mark(struct Student students[],int studentCount){
      float initial=0;
      float averagem;
      for(int i=0;i<studentCount;i++){
        initial+=students[i].mark;
      }
      averagem=initial/studentCount;
      return averagem;
}

float low_mark(struct Student students[],int studentCount){
   int i=1;
   float lowest=students[0].mark;

   for(i;i<studentCount;i++){
    if(lowest>students[i].mark){
        lowest=students[i].mark;
    }
   }
   return lowest;
}

void statistics(struct Student students[],int studentCount){
    if(studentCount==0){
        printf("No students record available\n");
        return;
    }
    int total=studentCount;
    float highest=high_mark(students,studentCount);
    float lowest=low_mark(students,studentCount);
    float average=average_mark(students,studentCount);

    printf("====STUDENTS STATISTICS====\n");
    printf("Total Students:%d\n",total);
    printf("Average Mark:%.2f\n",average);
    printf("Highest Mark:%.2f\n",highest);
    printf("Lowest Mark:%.2f\n",lowest);
}

void exitFunction(){
    printf("Exiting...");
}



void loadStudents(struct Student students[],int *studentCount){
    FILE *filename=fopen("student.txt","r");
    if(filename==NULL){
        return;
    }
    else{
        while(*studentCount<10 && 
             fscanf(filename,"%49[^,],%d,%f",
            students[*studentCount].name,
            &students[*studentCount].age,
            &students[*studentCount].mark)==3){ 
                if(((students[*studentCount].mark>=0) && (students[*studentCount].mark<=100)) && students[*studentCount].age>0){
                     (*studentCount)++;
                } else{
                    printf("there is an invalid value in this file\n");
                    fclose(filename);
                    return;
                } 
             
              
        }
        }fclose(filename) ;
        
    }
 //File manager

 //For adding File
 void createFile(){
    char file[50];
    char content[200];
    printf("Enter the File Name=");
    scanf("%49s",file);
    FILE *filename=fopen(file,"w");
    if (filename==NULL){
        printf("Something went wrong\n");
        return;
    }
    else{
        int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {
}
        printf("Enter the content:");
       if(fgets(content,sizeof(content),stdin)!=NULL)  {
         fprintf(filename,"%s",content);
         printf("File is created successfully");
       }
       else{
        printf("Something went wrong\n");

       }
       fclose(filename);
    }
    
 }

 //For viewing file
 void viewFile(){
    char content[200];
    char fn[50];
     printf("Enter the file name=");
     scanf("%49s",fn);
     int ch;
     while((ch=getchar())!='\n' && ch !=EOF){

     }
     FILE *filename=fopen(fn,"r");
     if(filename==NULL){
        printf("File not found\n");
     }
     else{
        int err=0;
        while(fgets(content,sizeof(content),filename)!=NULL){
     printf("%s",content);
     err++;
        }if(err==0){
            printf("File is empty\n");
        }fclose(filename);
     }  
 }

 //For Appending
 void appendFile(){
    char fn[50];
    char content[200];
    int ch;
    printf("Enter the filename to append:");
    scanf("%49s",fn);
    while((ch=getchar())!='\n' && ch !=EOF){
    
    }
    FILE *filename=fopen(fn,"a");
    if(filename==NULL){
        printf("FIle not found");
         }else{
            printf("Enter the content:");
    if(fgets(content,sizeof(content),stdin)!=NULL){
        fprintf(filename,"%s",content);
        printf("Content is appended");

    }else{
        printf("unable to write\n");
    }
     fclose(filename);   
    }
   
    
 }


int main(){

    struct Student students[10];
    int choice;
    int studentCount=0;
    loadStudents(students,&studentCount);
    do{ printf("====SYSTEM UTILITY====\n");
    printf("1.Student Records\n");
    printf("2.File Manager\n");
    printf("3.Statistics\n");
    printf("4.Exit\n");
    printf("Enter the choice=");
    if(scanf("%d",&choice)!=1){
         int ch;
while ((ch = getchar()) != '\n' && ch != EOF) {
}
        printf("Invalid Input\n");
        choice=0;
        continue;
}
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) { }
    switch (choice)
    {
    case 1:
        studentsRecords(students,&studentCount);
        break;
    case 2:
        fileManager();
        break;
    case 3:
        statistics(students,studentCount);
        break;
    case 4:
        exitFunction();
        break;
    
    default:
        printf("Invalid Choice\n");
        break;
    }} while(choice!=4);
   
    return 0;
}