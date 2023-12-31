#include <openssl/aes.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./encrypt");
    int bytes_read, bytes_written;
    unsigned char indata[AES_BLOCK_SIZE];
    unsigned char outdata[AES_BLOCK_SIZE];

    if ( d )
    {
        while ( (dir = readdir(d)) != NULL )
        {
            printf("%s\n", dir->d_name);
            char tmp1[256] = "./encrypt/";
            char tmp2[256] = "./decrypt/";

            FILE *ifp = fopen(strcat(tmp1, dir->d_name), "rb");
            FILE *ofp = fopen(strcat(tmp2, dir->d_name), "wb");


            /* ckey and ivec are the two 128-bits keys necesary to
               en- and recrypt your data.  Note that ckey can be
               192 or 256 bits as well */
            unsigned char ckey[16] = "thiskeyisverybad";
            unsigned char ivec[16] = "dontusethisinput";

            /* data structure that contains the key itself */
            AES_KEY key;

            /* set the encryption key */
            AES_set_encrypt_key(ckey, 128, &key);

            /* set where on the 128 bit encrypted block to begin encryption*/
            int num = 0;

            while ( 1 )
            {
                //fwrite(ivec, 1, AES_BLOCK_SIZE, ofp);
                bytes_read = fread(indata, 1, AES_BLOCK_SIZE, ifp);

                AES_cfb128_encrypt(indata, outdata, bytes_read, &key, ivec, &num, AES_ENCRYPT);
                bytes_written = fwrite(outdata, 1, bytes_read, ofp);
                if ( bytes_read < AES_BLOCK_SIZE )
                {
                    //fclose(ifp);
                    //fclose(ofp);
                    break;
                }
            }



        }
        closedir(d);
    }
    return(0);