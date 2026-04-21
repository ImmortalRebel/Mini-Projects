#include <stdio.h>
#include <string.h>

int main() 
{
   int book_id[10];
   char book_name[10][50];
   int book_quantity[10];
   int choice;
   int count = 0;
 

   while(1)
   {
        printf("\n------LIBRARY MANAGEMENT SYSTEM------\n\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Books\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // add books
        if (choice == 1)
        {    
            printf("\nAdding a Book\n--------------------\n");
            printf("Enter BookID : ");
            scanf("%d",&book_id[count]);

            printf("Enter Book name : ");
            scanf(" %[^\n]",book_name[count]);

            printf("Enter qty: ");
            scanf("%d",&book_quantity[count]);
            
            

            printf("\n%d %s were added successfully!!\n\n",book_quantity[count],book_name);
            printf("Number of %s books available now are :- %d\n",
                   book_name[count], book_quantity[count]);

            count++;
        }

        // display books
        if (choice== 2)
        {
            printf("\n%-5s %-20s %-5s\n","ID","Name","Quantity");
            printf("---------------------------------------------\n");

            for (int i = 0; i < count; i++)
            {
                printf("%-5d %-20s %-5d\n",
                       book_id[i], book_name[i], book_quantity[i]);
            }
        }

        // search book
        if (choice==3)
        {
            int ids;
            printf("\nEnter the ID of the Book: ");
            scanf("%d",&ids);

            for (int i = 0; i < count; i++)
            {
                if (book_id[i]==ids)
                {
                    printf("\nBOOK FOUND! \n");
                    printf("ID: %d\n",book_id[i]);
                    printf("Name: %s\n",book_name[i]);
                    printf("Qty: %d\n",book_quantity[i]);
                }
            }
        }

        // Issue the book
        if (choice==4)
        {
            int id;
            printf("\nEnter the book id you want to issue : ");
            scanf("%d",&id);

            for (int i = 0; i < count; i++)
            {
                if (book_id[i]==id)
                {
                    if (book_quantity[i]>0)
                    {
                        book_quantity[i]--;
                        printf("Book issued !!\n");
                        break;
                    }
                }
                else
                {
                    printf("Enter Valid BookID!\n");
                }
                
            }
        }

        // Return book
        if (choice==5)
        {
            int id;
            printf("\nEnter the Book id : ");
            scanf("%d",&id);

            for (int i = 0; i < count; i++)
            {
                if (book_id[i]==id)
                {
                    book_quantity[i]++;
                    printf("Book Returned !!\n");
                }
            }
        }

        // Exit
        if(choice == 6)
        {
            break;
        }
   }

   return 0;
}
