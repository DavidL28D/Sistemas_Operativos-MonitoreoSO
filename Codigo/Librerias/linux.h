#include "global.h"

#include <dirent.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

    FILE *a;
    char linea[128];
    char *token;

// ***** SECCION DEL SISTEMA *****
void kernel_version(){

    if ((a = fopen("/proc/version", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){
            
            if(strstr(linea, "Linux version")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                token = strtok(NULL, " ");

                printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                break;
            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

void running_processes(){

    DIR *dir;
    struct dirent *ent;
    int x = 0;
    bool flag;

    dir = opendir("/proc/");

    if (dir == NULL){
        printf("No se puede abrir el directorio.");

    }else{  

        while((ent = readdir (dir)) != NULL){

            flag = true;

            for(int i=0; i<strlen(ent->d_name); i++){
                if(!isdigit(ent->d_name[i])){
                    flag = false;
                    break;
                }
            }

            if(flag){
                x++;
            }

        }

        closedir (dir);

        int auxB, auxA;

        auxA = x;
        auxB = 1;

        while(true){

            auxA/=10;

            if(auxA > 0){
                auxB++;
            }else{
                break;
            }

        }

        char aux[auxB];
        sprintf(aux, "%i", x);

        printf("%s\n", aux); // VARIABLE(S) A RETORNAR PARA LA UI

    }

}

void current_user(){

    char *user;

    user = (char *)malloc(20);
    strcpy(user, getenv("USER"));

    printf("%s\n", user);

}

void date_time(){

    char *tiempo = (char *)malloc(128);
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    strftime(tiempo, 128, "%d/%m/%y %H:%M", tm);

    printf("%s\n", tiempo); // VARIABLE(S) A RETORNAR PARA LA UI

}

void uptime(){

    if ((a = fopen("/proc/uptime", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);

        while (!feof(a)){

            token = strtok(linea, ".");

            printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

            break;

        }

    }

    fclose(a);

}

// ***** SECCION DE MEMORIA *****
void mem_total(){

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){

            if(strstr(linea, "MemTotal")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

void mem_total_free(){

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){

            if(strstr(linea, "MemFree")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                break;
            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

void mem_swap(){

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){
            
            if(strstr(linea, "SwapTotal")){
                
                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

void mem_swap_free(){

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){
            
            if(strstr(linea, "SwapFree")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

// ***** SECCION DE DISCO *****

void disk_list(){ 

    int p, x, y;
    char pipe[] = "/tmp/pipe"; 
    char *string, *buffer = (char *)malloc(200);

    mkfifo(pipe, 0666);

    for(int i=0; i<2; i++){

        system("(fdisk -l | egrep 'Disco|Disk' > /tmp/pipe) &");

        p = open(pipe, O_RDONLY);

        if(i == 0){

            while((x = read(p, buffer, 200)) > 0){ y+=x; }

        }else{

            string = (char *) malloc(y);
            read(p, string, y);

        }
        
        close(p);

    }

    unlink(pipe);

    token = strtok (string, " :");

    while (token != NULL){

        if(strstr(token, "Disco") || strstr(token, "Disk")){

            token = strtok (NULL, " :");
            printf ("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

        }

        token = strtok (NULL, " :");

    }

}

void disk_space(){

}

void partitions_list(){

    if ((a = fopen("/proc/partitions", "r")) == NULL){
    printf("No se puede abrir el archivo");

    }else{

        for(int i=0; i<3; i++){
            fgets(linea, sizeof(linea), a);
        }
        
        token = strtok(linea, " ");

        for(int i=0; i<3; i++){
            token = strtok(NULL, " ");
        }
        
        while (!feof(a)){
            
            printf("%s", token); // VARIABLE(S) A RETORNAR PARA LA UI
            
            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

}

// ***** SECCION DE REDES *****
void net_list(){
    int p, x, tam=0;
    char pipe[] = "/tmp/pipe",*word; 
    char *string, *buffer = (char *)malloc(200);

    mkfifo(pipe, 0666);

        system("( ip address ls | egrep ': ' | sed 's/^[0-9]: *//g' > /tmp/pipe) &");
        p = open(pipe, O_RDONLY);
        
        for(int i = 0; i < 1; i++)
            while((x = read(p, buffer, 200)) > 0) 
                tam+=x; 

        system("( ip address ls | egrep ': ' | sed 's/^[0-9]: *//g' > /tmp/pipe) &");
        p = open(pipe, O_RDONLY);
        string = (char *) malloc(tam-1);
        read(p, string, tam-1);
        close(p);

        word = strtok (string, ":\n");

        while (word != NULL){
            if (word[0] != ' '){
                printf("%s\n",word);
                word = strtok (NULL, ":\n");
            }
            word = strtok (NULL, ":\n");
        }

    unlink(pipe);

}

void net_list_ip(){

}
