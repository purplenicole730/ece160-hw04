#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//mode numbers
typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

//student info
typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
  int years_left;
} Student;

//how to print modes of student info
void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%d %s %s\n", s.year, s.first_name, s.last_name);
      break;
    case YEARS_LEFT_AND_NAME:
      printf("%d %s %s\n", s.years_left, s.first_name, s.last_name);
      break;
  }
}

int main(int argc, char* argv[]) { 
  //opening input file
  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  
  //create buffer that can hold strings of 255 bytes each
  char buffer[256];
  Student student_array[256];
  
  //read one line at a time
  char *s;
  int i = 0;
  
  Student si;
  //Process input file
  while((s = fgets(buffer, 255, fp)) != NULL){
      size_t len = strlen(buffer);
      size_t len_bytes = (len + 1) * sizeof(char);
      
      si.first_name = malloc(len_bytes);
      si.last_name = malloc(len_bytes);
      si.major = malloc(len_bytes);
      sscanf(buffer, "%s %s %s %d", si.first_name, si.last_name, si.major, &si.year);
      si.years_left = si.year - 2017;
      student_array[i] = si;
      i++;
  }
  
  int m;
  while(1) {
      //Ask user to input index and mode number
      scanf("%d %d", &i, &m);
      //print chosen student's info in the selected mode
      print_student(m, student_array[i]); 
  }
    
  fclose(fp);
  return 1;
}