#include <stdio.h>
struct Employee
{
    int id;
    char name[50];
    float salary;
};
int main()
{
    struct Employee e;
    FILE *fp;
    int n,i;

    fp=fopen("employee.dat","wb+");
    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter details of employee %d:\n",i+1);
        printf("ID: ");
        scanf("%d",&e.id);
        printf("Name: ");
        scanf("%s",e.name);
        printf("Salary: ");
        scanf("%f",&e.salary);

        fwrite(&e,sizeof(e),1,fp);
    }
    rewind(fp);
    for(i=0;i<n;i++)
    {
        fread(&e,sizeof(e),1,fp);

        if(e.salary>50000)
            e.salary=e.salary+e.salary*0.05;
        else if(e.salary>20000)
            e.salary=e.salary+e.salary*0.10;
        else
            e.salary=e.salary+e.salary*0.15;

        fseek(fp,-sizeof(e),1);
        fwrite(&e,sizeof(e),1,fp);
    }
    rewind(fp);
    printf("Updated Employee Details:\n");
    for(i=0;i<n;i++)
    {
        fread(&e,sizeof(e),1,fp);
        printf("\nID: %d",e.id);
        printf("\nName: %s",e.name);
        printf("\nUpdated Salary: %.2f\n",e.salary);
    }
    fclose(fp);
    return 0;
}