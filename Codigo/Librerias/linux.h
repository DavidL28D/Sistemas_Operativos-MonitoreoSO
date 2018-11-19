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
char* kernel_version(){

    char *retorno;

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

    retorno = (char *) malloc(strlen(linea));
    strcpy(retorno, linea);
    //return retorno;
    return linea;

}

int running_processes(){

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
        return atoi(aux);

    }

    return 0;
}

char* current_user(){

    char *user;

    user = (char *)malloc(20);
    strcpy(user, getenv("USER"));

    printf("%s\n", user);

    return user;
}

char* date_time(){

    char *retorno;
    char *tiempo = (char *)malloc(128);
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    strftime(tiempo, 128, "%d/%m/%y %H:%M", tm);

    printf("%s\n", tiempo); // VARIABLE(S) A RETORNAR PARA LA UI

    return tiempo;

}

char* uptime(){

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

    return token;

}

// ***** SECCION DE MEMORIA *****
float mem_total(){

    float memoria;

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){

            if(strstr(linea, "MemTotal")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                //printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                memoria = (float) atol(token);
                memoria /= 1048576;

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);
    
    printf("%.2f GB\n", memoria);
    return memoria;

}

float mem_total_free(){

    float memoria;

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){

            if(strstr(linea, "MemFree")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                //printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                memoria = (float) atol(token);
                memoria /= 1048576;

                break;
            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

    printf("%.2f GB\n", memoria);
    return memoria;

}

float mem_swap(){
    
    float memoria;

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){
            
            if(strstr(linea, "SwapTotal")){
                
                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                //printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                memoria = (float) atol(token);
                memoria /= 1048576;

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

    printf("%.2f GB\n", memoria);
    return memoria;

}

float mem_swap_free(){

    float memoria;

    if ((a = fopen("/proc/meminfo", "r")) == NULL){
    printf("No se puede abrir el archivo");
        
    }else{

        fgets(linea, sizeof(linea), a);
        while (!feof(a)){
            
            if(strstr(linea, "SwapFree")){

                token = strtok(linea, " ");
                token = strtok(NULL, " ");
                
                //printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

                memoria = (float) atol(token);
                memoria /= 1048576;

                break;

            }

            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

    printf("%.2f GB\n", memoria);
    return memoria;

}

// ***** SECCION DE DISCO *****
char** disk_list(){ 

    int p, x, y;
    char pipe[] = "/tmp/pipe"; 
    char *string, *buffer = (char *)malloc(200), *aux;
    char **disks;

    mkfifo(pipe, 0666);

    for(int i=0; i<2; i++){

        system("(fdisk -l | egrep 'Disco|Disk' > /tmp/pipe) &");

        p = open(pipe, O_RDONLY);

        if(i == 0){

            while((x = read(p, buffer, 200)) > 0){ y+=x; }

        }else{

            string = (char *) malloc(y);
            aux = (char *) malloc(y);
            read(p, string, y);

        }
        
        close(p);

    }

    unlink(pipe);
    x=0;

    token = strtok (string, " :");

    while (token != NULL){

        if(strstr(token, "Disco") || strstr(token, "Disk")){

            token = strtok (NULL, " :");
            //printf ("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

            strcat(aux, token);
            strcat(aux, "-");
            x++;

        }

        token = strtok (NULL, " :");

    }

    token = strtok (aux, "-");
    disks = (char **) malloc(x);

    for(int i=0; i<x; i++){
        disks[i] = (char *) malloc(strlen(token));
        strcpy(disks[i], token);
        token = strtok(NULL, "-");

        printf("%s\n", disks[i]);
    }

    return disks;

}

char** disk_space(){

    int p, x, y;
    char pipe[] = "/tmp/pipe"; 
    char *string, *aux, *buffer = (char *)malloc(200);
    char** disks;

    mkfifo(pipe, 0666);

    for(int i=0; i<2; i++){

        system("(df -h | grep /dev/sd > /tmp/pipe) &");

        p = open(pipe, O_RDONLY);

        if(i == 0){

            while((x = read(p, buffer, 200)) > 0){ y+=x; }

        }else{

            string = (char *) malloc(y);
            aux = (char *) malloc(y);
            read(p, string, y);

        }
        
        close(p);

    }

    unlink(pipe);

    token = strtok (string, " ");

    x=0;
    while (token != NULL){

        // printf("%s: ", token);
        strcat(aux, token);
        strcat(aux, ": ");

        if(strstr(token, "Disco") || strstr(token, "Disk")){

            token = strtok (NULL, " :");
            // printf ("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

        }

        for(int i=0; i<3; i++){
            token = strtok (NULL, " ");
        } 

        // printf("%s\n", token); // VARIABLE(S) A RETORNAR PARA LA UI

        strcat(aux, token);
        strcat(aux, "-");

        token = strtok (NULL, "\n");
        token = strtok (NULL, " ");
        x++;

    }

    token = strtok (aux, "-");
    disks = (char **) malloc(x);

    for(int i=0; i<x; i++){
        disks[i] = (char *) malloc(strlen(token));
        strcpy(disks[i], token);
        token = strtok(NULL, "-");

        printf("%s\n", disks[i]);
    }

    return disks;

}

char** partitions_list(){

    char *aux = (char *)malloc(512);
    char **partitions;
    int x=0;

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
            
            //printf("%s", token); // VARIABLE(S) A RETORNAR PARA LA UI
            strcat(aux, token);
            x++;
            fgets(linea, sizeof(linea), a);

        }

    }

    fclose(a);

    token = strtok (aux, "\n");
    partitions = (char **) malloc(x);

    for(int i=0; i<x; i++){
        partitions[i] = (char *) malloc(strlen(token));
        strcpy(partitions[i], token);
        token = strtok(NULL, "\n");

        printf("%s\n", partitions[i]);
    }

    return partitions;

}

// ***** SECCION DE REDES *****
char** net_list(){
    int p, x, tam=0, lenght=0;
    char pipe[] = "/tmp/pipe", *word; 
    char *string, *buffer = (char *)malloc(200),**interfaces;
    char *aux, *cadena;

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
        unlink(pipe);
        strcpy(aux,string);
        word = strtok (string, ":\n");
        x = 0;
        
        while (word != NULL){
            if (word[0] != ' '){
                x++;
                lenght+= strlen(word);
                word = strtok (NULL, ":\n");
            }//if
            word = strtok (NULL, ":\n");
        }//while
        lenght+=3;
        cadena = (char*)malloc(lenght+1);
        word = strtok (aux, ":\n");
        
        while (word != NULL){
            if (word[0] != ' '){
                strcat(cadena,word);
                strcat(cadena,"-");
                word = strtok (NULL, ":\n");
            }//if
            word = strtok (NULL, ":\n");
        }//while

        interfaces = (char**)malloc(x);
        
        aux = strtok(cadena,"-");
        for(int i = 0; i < x; i++){
            interfaces[i] = (char*)malloc(strlen(aux));
            strcpy(interfaces[i],aux);
            aux = strtok (NULL, "-");
        }//for
    return interfaces;
}

void net_list_ip(){

}
