#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARCHIVO ".info.txt"
#define ESCRIBIR 0
#define ESCRIBIR_ACTUALIZAR 1

#ifdef __unix__ 

    #include <dirent.h>

    FILE *a;
    char linea[100];

#elif defined(_WIN32) || defined(WIN32)

    // includes para windows

#endif

void esperar(){
	
    #ifdef __unix__

        printf("\nPulsa enter para continuar...");
        while(getchar()!='\n');

    #elif defined(_WIN32) || defined(WIN32)
		
		printf("\n");
        system("pause");

	#endif
        
}

void limpiar(){

    #ifdef __unix__

        system("clear");

    #elif defined(_WIN32) || defined(WIN32)

        system("cls");

    #endif     

}

void info(char *valor, int x){

    FILE *b;

    if(x == ESCRIBIR){
        b = fopen(ARCHIVO, "w");

    }else if( x == ESCRIBIR_ACTUALIZAR){
        b = fopen(ARCHIVO, "a+");
    }

    if (b == NULL){

        printf("No se pudo abrir el archivo.\n");
        
    }else{

        fputs(valor, b);
        //printf("Se escribio en el archivo la linea: %s\n", valor);

    }

    fclose(b);
    
}

// ***** SECCION DEL SISTEMA *****
void kernel_version(){

    #ifdef __unix__

        if ((a = fopen("/proc/version", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);
            while (!feof(a)){
                
                if(strstr(linea, "Linux version")){
                    break;
                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);

        char *token;

        token = strtok(linea, " ");
        token = strtok(NULL, " ");
        token = strtok(NULL, " ");

        printf("%s\n", token);
        info(token, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

        /*
        FILE *pipe;
        char buf[128];
        pipe = _popen("ver","r"); // escribe el resultado de dir en pipe
        printf("holahola");
        fgets (buf, 128,pipe);
        printf("Version del kernel: %s",buf);
        */
        system("ver");
        system("ver>>.info.txt");
        //char cmd[30]="";
        //strcat(cmd, "C:/Windows/System32/attrib +h ");
        //strcat(cmd, ARCHIVO );
        //system(cmd);
        system("C:/Windows/System32/attrib +h .info.txt");

    #endif 

}

void running_processes(){

    #ifdef __unix__

        DIR *dir;
        struct dirent *ent;
        int x = 0;
        bool flag;

        dir = opendir("/proc/");

        if (dir == NULL){
            printf("No se puede abrir el directorio.");

        }else{  

            while((ent = readdir (dir)) != NULL){

                // Nos devolverá el directorio actual 
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
            printf("%s", aux);
            info(aux, ESCRIBIR);

        }

    #elif defined(_WIN32) || defined(WIN32)

        //system("C://Windows/System32/TASKLIST >> procesos.txt");
        FILE *pipe,*arc;
        char buf[128];
        int cantProcesos=0;
        printf("Abriendo la Tubería de lectura\n");
        pipe = _popen("C://Windows/System32/TASKLIST","r"); // escribe el resultado de dir en pipe

        if(!pipe){

            printf("Tuberia no accedida.\n");

        }else{

            while (fgets(buf, 128, pipe) != NULL) {

                cantProcesos++;

            }

        }

        printf("Hay %d procesos.",(cantProcesos)-3);
        _pclose(pipe);
        arc=fopen(".info.txt","a");

        if(arc == NULL){

            printf("No Se puede abrir el archivo");

        }else{

            fprintf(arc,"%d",(cantProcesos)-3);

        }
        char cmd[30]="";
        strcat(cmd, "C:/Windows/System32/attrib +h ");
        strcat(cmd, ARCHIVO );
        fclose(arc);
        system(cmd);
        //system("C:/Windows/System32/attrib +h %S",ARCHIVO);
        
    #endif 

}

void current_user(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void date_time(){

    #ifdef __unix__
        system("date >> .info.txt");

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void uptime(){

    #ifdef __unix__

        int pos;
        char aux[strlen(linea)];


        if ((a = fopen("/proc/uptime", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);

            while (!feof(a)){

                pos = 0;

                for(int i=0; i<strlen(linea); i++){

                    if(isdigit(linea[i])){

                        aux[pos] = linea[i];
                        pos++;

                    }else if(linea[i] == '.'){

                        break;

                    }
                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);

        printf("%s", aux);
        info(aux, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}


// ***** SECCION DE MEMORIA *****
void mem_total(){

    #ifdef __unix__

        char aux[strlen(linea)];
        int pos;

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);
            while (!feof(a)){

                if(strstr(linea, "MemTotal")){

                    pos = 0;
                    //printf("%s\n", linea); // imprime la linea extraida del archivo

                    for(int i=0; i<strlen(linea); i++){

                        if(isdigit(linea[i])){

                            aux[pos] = linea[i];
                            pos++;

                        }
                    }

                    break;

                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);

        printf("%s", aux);
        info(aux, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_total_free(){

    #ifdef __unix__

        int pos;
        char aux[strlen(linea)];

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
            printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);
            while (!feof(a)){

                if(strstr(linea, "MemFree")){

                    pos = 0;
                    //printf("%s\n", linea); // imprime la linea extraida del archivo

                    for(int i=0; i<strlen(linea); i++){

                        if(isdigit(linea[i])){

                            aux[pos] = linea[i];
                            pos++;

                        }
                    }

                    break;
                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);
        printf("%s", aux);
        info(aux, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap(){

    #ifdef __unix__

        int pos;
        char aux[strlen(linea)];

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);
            while (!feof(a)){
                
                if(strstr(linea, "SwapTotal")){
                    
                    pos = 0;
                    //printf("%s\n", linea); // imprime la linea extraida del archivo

                    for(int i=0; i<strlen(linea); i++){

                        if(isdigit(linea[i])){

                            aux[pos] = linea[i];
                            pos++;

                        }
                    }

                    break;

                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);
        printf("%s", aux);
        info(aux, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void mem_swap_free(){

    #ifdef __unix__

        int pos;
        char aux[strlen(linea)];

        if ((a = fopen("/proc/meminfo", "r")) == NULL){
        printf("No se puede abrir el archivo");
            
        }else{

            fgets(linea, sizeof(linea), a);
            while (!feof(a)){
                
                if(strstr(linea, "SwapFree")){

                    pos = 0;
                    //printf("%s\n", linea); // imprime la linea extraida del archivo

                    for(int i=0; i<strlen(linea); i++){

                        if(isdigit(linea[i])){

                            aux[pos] = linea[i];
                            pos++;

                        }
                    }

                    break;

                }

                fgets(linea, sizeof(linea), a);

            }

        }

        fclose(a);
        printf("%s", aux);
        info(aux, ESCRIBIR);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

// ***** SECCION DE DISCO *****

void disk_list(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void disk_space(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void partitions_list(){

    #ifdef __unix__

        char *token;

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
            
            info(token, ESCRIBIR);

            while (!feof(a)){
                
                printf("%s", token);
                fgets(linea, sizeof(linea), a);

                if(!feof(a)){
                    info(token, ESCRIBIR_ACTUALIZAR);
                }
                
            }

        }

        fclose(a);

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

// ***** SECCION DE REDES *****
void net_list(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

void net_list_ip(){

    #ifdef __unix__

    #elif defined(_WIN32) || defined(WIN32)

    #endif 

}

// ***** SECCION DE AYUDA *****
void help(){

    printf("             COMANDO - FUNCION\n\n");

    printf("       **** SECCION DEL SISTEMA ****\n");
    printf("    --kernel-version - Muestra la version del kernel actual.\n");
    printf(" --running-processes - posero de procesos ejecutandose en el sistema.\n");
    printf("      --current-user - Muestra el nombre de usuario con el cual fue ejecutado el progama.\n");
    printf("         --date-time - Muestra la hora y fecha actual del sistema.\n");
    printf("            --uptime - Muestra el tiempo que ha estado encendida la computadora.\n\n");

    printf("       **** SECCION DE MEMORIA ****\n");
    printf("         --men-total - Total de memoria RAM.\n");
    printf("    --mem-total-free - Total de memorio RAM libre.\n");
    printf("          --men-swap - Total de memoria SWAP.\n");
    printf("     --mem-swap-free - Total de memoria SWAP libre en el sistema.\n\n");

    printf("       **** SECCION DEL DISCO ****\n");
    printf("         --disk-list - Lista de discos existentes en el sistema.\n");
    printf("        --disk-space - Muestra el espacio usado en los discos montados.\n");
    printf("   --partitions-list - Lista las particiones existentes en todos las unidades del sistema.\n\n");

    printf("      **** SECCION DE LA RED ****\n");
    printf("          --net-list - Lista las interfaces de red.\n");
    printf("       --net-list-ip - Lista las interfaces de red junto a su IP (si tiene asignada).\n\n");

}