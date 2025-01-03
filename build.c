#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int kernel = open("kernel.bin", O_CREAT | O_WRONLY, 0664);
    int temp;
    int c;
    char buf[512];

    // boot16
    temp = open("boot16.bin", O_RDONLY);
    while (1)
    {
        c = read(temp, buf, 512);
        if (c > 0)
        {
            write(kernel, buf, c);
        }
        else
        {
            break;
        }
    };
    close(temp);

    lseek(kernel, 0x20000 - 0x10000, SEEK_SET);

    // boot32
    temp = open("boot32.bin", O_RDONLY);
    while (1)
    {
        c = read(temp, buf, 512);
        if (c > 0)
        {
            write(kernel, buf, c);
        }
        else
        {
            break;
        }
    };
    close(temp);

    //lseek(kernel, 0x100000 - 0x10000, SEEK_SET);

    // // head64
    // temp = open("head64.bin", O_RDONLY);
    // while (1)
    // {
    //     c = read(temp, buf, 512);
    //     if (c > 0)
    //     {
    //         write(kernel, buf, c);
    //     }
    //     else
    //     {
    //         break;
    //     };
    //     close(temp);
    // };

    // close(kernel);
    return 0;
}