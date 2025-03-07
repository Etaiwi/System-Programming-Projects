/* ID1 = 315875385      ID2 = 211685300 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
typedef struct student {
    char *name;
    int  id;
    struct clist *courses;
} student;

typedef struct course {
    char *title;
    int  number;
    struct slist *students;
} course;

typedef struct slist {
    student      *info;
    struct slist *next;
} slist;

typedef struct clist {
    course       *info;
    struct clist *next;
} clist;


/* our functions */
char* char_allocation_and_initialization(char *name_or_title);
clist* create_clist(char *title, int number);
slist* create_slist(char *name, int id);
course* create_course(char *title, int number);
student* create_student(char *name, int id);
slist* insert_slist(slist *students, slist *newNode);
clist* insert_clist(clist *courses, clist *newNode);
clist* create_clist_for_student(course *crs);
slist* create_slist_for_course(student *std);
student* search_student(slist *students, int id);
course* search_course(clist *courses, int number);
clist* remove_course_from_student(clist *courses, int number);
slist* remove_student_from_course(slist *students, int id);
void free_student_courses(clist *cl);
void free_course_students(slist *sl);
void free_student(student *std);
void free_course(course *crs);
void free_students(slist *students);
void free_courses(clist *courses);
/* prototypes */
slist* add_student(slist *students, char *name, int id);    /* finished */
clist* add_course(clist *courses, char *title, int number); /* finished */
void reg_student(slist *students, clist *courses, int id, int number);  /* finished */
void unreg_student(slist *students, int id, int number);    /* finished */
void print_students(slist *students);   /* finished */
void print_courses(clist *courses); /* finished */
void free_all(slist *sl, clist *cl);

/*DO NOT TOUCH THIS FUNCTION */
static void getstring(char *buf, int length) {
    int len;
    buf = fgets(buf, length, stdin);
    len = (int) strlen(buf);
    if (buf[len-1] == '\n')
        buf[len-1] = '\0';
}

/*DO NOT TOUCH THIS FUNCTION */
int main() {
    slist* students = 0;
    clist* courses = 0;
    char  c;
    char  buf[100];
    int   id, num;

    do {
        printf("Choose:\n"
               "    add (s)tudent\n"
               "    add (c)ourse\n"
               "    (r)egister student\n"
               "    (u)nregister student\n"
               "    (p)rint lists\n"
               "    (q)uit\n");

        while ((c = (char) getchar()) == '\n');
        getchar();

        switch (c) {
            case 's':
                printf("Adding new student.\n");

                printf("Student name: ");
                getstring(buf, 100);

                printf("Student ID: ");
                scanf("%d", &id);

                students = add_student(students, buf, id);

                break;

            case 'c':
                printf("Adding new course.\n");

                printf("Course name: ");
                getstring(buf, 100);

                printf("Course number: ");
                scanf("%d", &num);

                courses = add_course(courses, buf, num);

                break;

            case 'r':
                printf("Registering a student to a course.\n");

                printf("Student ID: ");
                scanf("%d", &id);

                printf("Course number: ");
                scanf("%d", &num);

                reg_student(students, courses, id, num);

                break;

            case 'u':
                printf("Unregistering a student from a course.\n");

                printf("Student ID: ");
                scanf("%d", &id);

                printf("Course number: ");
                scanf("%d", &num);

                unreg_student(students, id, num);

                break;

            case 'p':
                printf("Printing Information.\n");

                print_students(students);
                print_courses(courses);

                break;

            case 'q':
                printf("Quitting...\n");
                break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    free_all(students,courses);
    return 0;
}

/* Memory allocation for name or title and initiating it with given string, return pointer to the memory */
char* char_allocation_and_initialization(char *name_or_title) {
    char *str;
    int size;
    size = (int)strlen(name_or_title);   /* len of name or title */
    str = (char *) malloc(sizeof(char)*(size+1));    /* size = len of string, and +1 for \0 */
    strcpy(str,name_or_title);  /* initiate name/title to the student/course */
    return str;
}

/* Creating CList using DMA for a single student */
clist* create_clist_for_student(course *crs) {
    clist *cl = (clist *) malloc(sizeof(clist));   /* memory allocation for clist for a single student */
    if (cl == NULL) exit(1);    /* memory allocation failure */
    cl->info = crs; /* cl is initially empty */
    cl->next = NULL;
    return cl;
}

/* Creating SList using DMA for a single student */
slist* create_slist_for_course(student *std) {
    slist *sl = (slist *) malloc(sizeof(slist));   /* memory allocation for slist for a single course */
    if (sl == NULL) exit(1);    /* memory allocation failure */
    sl->info = std;     /* sl is initially empty */
    sl->next = NULL;
    return sl;
}

/* Creating Student using DMA */
student* create_student(char *name, int id) {
    student *std = (student *) malloc(sizeof(student));    /* memory allocation for student */
    if (std == NULL) exit(1);   /* memory allocation failure */
    std->id = id;   /* initiate id to the student */
    std->name = char_allocation_and_initialization(name);   /* initiate name to the student */
    std->courses = NULL;    /* during creation of student, no courses are registered */
    return std;
}

/* Creating Course using DMA */
course* create_course(char *title, int number) {
    course *crs = (course *) malloc(sizeof(course));    /* memory allocation for course */
    if (crs == NULL) exit(1);   /* memory allocation failure */
    crs->number = number;   /* initiate number to the course */
    crs->title = char_allocation_and_initialization(title);   /* initiate title to the course */
    crs->students = NULL;   /* during creation of course, no students are registered */
    return crs;
}

/* Creating SList using DMA (Include creating student) */
slist* create_slist(char *name, int id) {
    slist *sl = (slist *) malloc(sizeof(slist));   /* memory allocation for slist */
    if (sl == NULL) exit(1);    /* memory allocation failure */
    sl->info = create_student(name, id);    /* create student with given data */
    sl->next = NULL;    /* initiate next node to NULL */
    return sl;
}

/* Creating CList using DMA (Include creating course) */
clist* create_clist(char *title, int number) {
    clist *cl = (clist *) malloc(sizeof(clist));   /* memory allocation for clist */
    if (cl == NULL) exit(1);    /* memory allocation failure */
    cl->info = create_course(title, number);    /* create course with given data */
    cl->next = NULL;    /* initiate next node to NULL */
    return cl;
}

/* Insert Student by id from low to high */
slist* insert_slist(slist *students, slist *newNode) {
    slist *currItem = students;
    if (students == NULL) return newNode;   /* if the students list was empty */
    else if (newNode->info->id < students->info->id) {   /* check if newNode's student id is smaller than all id of other students and should be first  */
        newNode->next = students;
        return newNode;
    }
    while(currItem->next && newNode->info->id > currItem->next->info->id) currItem = currItem->next;    /* find spot to put newNode in Students */
    newNode->next = currItem->next; /* newNode points to next in line for the current item */
    currItem->next = newNode;   /* current item points to newNode */
    return students;
}

/* Insert course by number from low to high */
clist* insert_clist(clist *courses, clist *newNode) {
    clist *currItem = courses;
    if (courses == NULL) return newNode;   /* if the courses list was empty */
    else if (newNode->info->number < courses->info->number) {   /* check if newNode's course number is smaller than all numbers of other courses and should be first  */
        newNode->next = courses;
        return newNode;
    }
    while(currItem->next && newNode->info->number > currItem->next->info->number) currItem = currItem->next;    /* find spot to put newNode in Courses */
    newNode->next = currItem->next; /* newNode points to next in line for the current item */
    currItem->next = newNode;   /* current item points to newNode */
    return courses;
}

/* Search student with id in Students */
student* search_student(slist *students, int id) {
    while (students) {
        if(students->info->id == id) return students->info;
        students = students->next;
    }
    return NULL;
}

/* Search course with number in Courses */
course* search_course(clist *courses, int number){
    while (courses){
        if (courses->info->number == number) return courses->info;
        courses = courses->next;
    }
    return NULL;
}

/* Create new Student using DMA and allocating to Students */
slist* add_student(slist *students, char *name, int id) {
    slist *sl = create_slist(name,id); /* using DMA, creating the structs needed for slist students */
    students = insert_slist(students, sl);    /* insert into a sorted list by id */
    return students;
}

/* Create new Course using DMA and allocating to Courses */
clist* add_course(clist *courses, char *title, int number) {
    clist *cl = create_clist(title,number);    /* using DMA, creating the structs needed for clist courses */
    courses = insert_clist(courses, cl);    /* insert into a sorted list by number */
    return courses;
}

/* Print Students */
void print_students(slist *students){
    slist *currItem;
    clist *currCourse;
    if (students == 0) printf("STUDENT LIST: EMPTY!\n");    /* There are no students */
    else {
        currItem = students;
        printf("STUDENT LIST:\n");
        do {    /* while there is at least 1 student in Students SList, first print it and then move forward */
            printf("%d:%s\n", currItem->info->id,currItem->info->name); /* print id:name of given student */
            if (currItem->info->courses == NULL) printf("student is not registered for courses.\n");  /* no courses registered to the student */
            else {  /* student is registered to 1 or more courses */
                currCourse = currItem->info->courses;
                printf("courses: ");
                while (currCourse->next) {  /* next registered course is not NULL */
                    printf("%d-%s, ",currCourse->info->number,currCourse->info->title);   /* print number-title */
                    currCourse = currCourse->next;    /* move to next course in student courses clist */
                }
                printf("%d-%s\n",currCourse->info->number,currCourse->info->title);    /* print last number-title */
            }
            currItem = currItem->next;  /* move to next student in Students SList */
        }
        while(currItem != NULL);  /* check if we went over all students in Students SList, finish if there are no more students */
    }
}

/* Print Courses */
void print_courses(clist *courses){
    slist *currStudent;
    clist *currItem;
    if (courses == 0) printf("COURSE LIST: EMPTY!\n");  /* There are no courses */
    else {
        currItem = courses;
        printf("COURSE LIST:\n");
        do {    /* while there is at least 1 course in Courses CList, first print it and then move forward */
            printf("%d:%s\n", currItem->info->number,currItem->info->title);    /* print number:title of given course */
            if (currItem->info->students == NULL) printf("course has no students.\n");  /* no students registered to the course */
            else {  /* course has 1 or more registered students */
                currStudent = currItem->info->students;
                printf("students: ");
                while (currStudent->next) { /* next registered student is not NULL */
                    printf("%d-%s, ",currStudent->info->id,currStudent->info->name);   /* print id-name */
                    currStudent = currStudent->next;    /* move to next student in course students slist */
                }
                printf("%d-%s\n",currStudent->info->id,currStudent->info->name);    /* print last id-name */
            }
            currItem = currItem->next;  /* move to next course in Courses CList */
        }
        while(currItem != NULL);  /* check if we went over all courses in Courses CList, finish if there are no more courses */
    }
}

/* Register student to a course and updating the lists */
void reg_student(slist *students, clist *courses, int id, int number) {
    student *std = search_student(students,id); /* pointer to the student with given id */
    course *crs = search_course(courses,number);    /* pointer to the course with given number */
    clist *cl = create_clist_for_student(crs);
    slist *sl = create_slist_for_course(std);
    std->courses = insert_clist(std->courses, cl);  /* insert given course to given student courses */
    crs->students = insert_slist(crs->students, sl);    /* insert given student to given course students */
}

/* Remove course with given number from given student clist and free that space */
clist* remove_course_from_student(clist *courses, int number) {
    clist *curr = courses, *prev = NULL;
    if(!courses) {  /* student not registered to any courses */
        return NULL;
    }
    else if(courses->info->number == number) {  /* unregister the first course in student courses */
        courses = courses->next;
        free(curr); /* free memory allocated to the space in courses of unregistered course */
        return courses;
    }
    while(curr) {
        if(curr->info->number == number) {  /* current course number found */
            prev->next = curr->next;
            free(curr); /* free memory allocated to the space in courses of unregistered course */
            return courses;
        }
        prev = curr;
        curr = curr->next;
    }
    return courses;
}

/* Remove student with given id from given course slist and free that space */
slist* remove_student_from_course(slist *students, int id) {
    slist *curr = students, *prev = NULL;
    if(!students) {  /* course doesn't have any students */
        return NULL;
    }
    else if(students->info->id == id) {  /* unregister the first student in course students */
        students = students->next;
        free(curr); /* free memory allocated to the space in students of unregistered student */
        return students;
    }
    while(curr) {
        if(curr->info->id == id) {  /* current student id found */
            prev->next = curr->next;
            free(curr); /* free memory allocated to the space in courses of unregistered course */
            return students;
        }
        prev = curr;
        curr = curr->next;
    }
    return students;
}

/* Unregister student from a course */
void unreg_student(slist *students, int id, int number) {
    clist *cl;
    slist *sl;
    student *std;
    course *crs;
    std = search_student(students, id);    /* find student with given id in Students SList */
    cl = std->courses;   /* initiate courses of given student */
    crs = search_course(cl, number);    /* find course with given number in given student registered courses */
    sl = crs->students;  /* initiate students of given course */
    std->courses = remove_course_from_student(cl, number);  /* remove course from student registered courses */
    crs->students = remove_student_from_course(sl, id);    /* remove student from course registered students */
}

/* Free all student registered courses */
void free_student_courses(clist *cl) {
    clist *temp, *curr = cl;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

/* Free all course registered students */
void free_course_students(slist *sl) {
    slist *temp, *curr = sl;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

/* Free single student */
void free_student(student *std) {
    free(std->name);
    free_student_courses(std->courses);
    free(std);
}

/* Free single course */
void free_course(course *crs) {
    free(crs->title);
    free_course_students(crs->students);
    free(crs);
}

/* Free all Students SList */
void free_students(slist *students) {
    slist *temp, *curr = students;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;  /* move forward in Students SList */
        free_student(temp->info);   /* free current student in Students SList */
        free(temp);
    }
}

/* Free all Courses CList */
void free_courses(clist *courses) {
    clist *temp, *curr = courses;
    while(curr != NULL) {
        temp = curr;
        curr = curr->next;  /* move forward in Courses CList */
        free_course(temp->info);    /* free current course in Courses CList */
        free(temp);
    }
}

/* Free all DMA */
void free_all(slist *sl, clist *cl) {
    free_students(sl);    /* free all Students SList */
    free_courses(cl);  /* free all Courses CList */
}