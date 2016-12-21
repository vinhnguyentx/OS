#include <dirent.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    char *directory = argv[1];
    DIR * dirp;
    struct dirent *entry;
    dirp = opendir(directory);

    entry = readdir(dirp);
    while (entry) {
        printf("Filename: %s   inode %llu \n", entry->d_name, entry->d_ino);
        entry = readdir(dirp);
    }
    closedir(dirp);
}
