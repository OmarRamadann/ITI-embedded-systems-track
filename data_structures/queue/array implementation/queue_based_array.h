#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_

#define Max_Size       5 
#define Empty          1
#define NotEmpty       0
#define NotFully       0 
#define Fully          1 



//s8 front = -1 ;     //Anwer -> index number 0 
//s8 rear= -1 ;    // Anwer -> 

void EnQueue(u8 Data);
u8 DeQueue(void);
u8 IsEmpty(void);
u8 IsFul(void);
u8* display  (void);
#endif