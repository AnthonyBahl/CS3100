#include <stdio.h>
#include <string.h>

struct student
    {
        char name[50];
        int id;         
        double gpa;
        char grade;
    }; 

// gradeMesg function will return a message, 
// that is a text string based on the students grade.
// if grade is 'A' return "You are rocking!\n"
// else if grade is 'B' return "You can do better!\n"
// else if grade is 'C' return "More haradwork needed!\n"
// else return "Unknown.\n"
// Please use a switch statement
// This function should NOT have a printf statement
char* gradeMesg(struct student s)
{
    switch (s.grade)
    {
    case 'A':
        return "You are rocking!\n";
        break;
    case 'B':
        return "You can do better!\n";
        break;
    case 'C':
        return "More haradwork needed!\n";
        break;
    default:
        return "Unknown.\n";
        break;
    }
}


// dispStudInfo() displays student information
void dispStudInfo(struct student s)
{
    printf("stud details: %s, ID: %d, GPA: %.2f, Grade: %c\n", s.name, s.id, s.gpa, s.grade);
    char *mesg;

    mesg = gradeMesg(s);
    printf(mesg);
}


int main()
{
    struct student s1;
    struct student s2;

    strcpy(s1.name, "Allen Smith");
    s1.id = 312;
    s1.gpa = 3.4;
    s1.grade = 'A';

    dispStudInfo(s1);   
    printf("\n");   

    //strcpy(s2.name, "Mary Lo");
   
    fgets(s2.name, 80, stdin);

    int l = strlen(s2.name);

    printf("Len of name is: %d\n", l);

    s2.name[l-1] = '\0';

    s2.id = 12;
    s2.gpa = 3.5;
    s2.grade = 'B';

     dispStudInfo(s2);  
     printf("\n");   

    return 0;

}