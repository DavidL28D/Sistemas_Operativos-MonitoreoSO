#include "global.h"

#include <dirent.h>

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

}

void net_list_ip(){

}
