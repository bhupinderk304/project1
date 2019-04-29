#include<stdio.h>
#include<string.h>
// void rotation();
 //void rotation_dec(char message[100]);
 
//int main()
//{
//    rotation();
//    rotation_decrypt();
//    substitution();
//}
void rotation()
{
	char message[100], ch;
	int i, key;
    printf("_____ROTATION ENCRYPTION_____\n\n");	
	//printf("Enter a message to encrypt: ");
	scanf("%s",message);
	printf("Enter a message to encrypt: %s \n", message);
	//printf("Enter key: ");
	scanf("%d", &key);
	printf("Enter key: %d\n", key);
	
	for(i = 0; message[i] != '\0'; ++i)
	{
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch + key;
			
			if(ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	
	printf("Encrypted message: %s\n\n", message);
}
void rotation_decrypt()
{
    char message[100], ch;
	int i, key;
	
	//char message1[]=message[];
	printf("_____ROTATION DECRYPTION_____\n\n");
	printf("Decrypt the above message using the key\n");
	//scanf("%s",&message);
	//printf("Enter key: ");
	scanf("%d", &key);
	printf("Enter key: %d \n", key);
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			
			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			
			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Decrypted message: %s\n\n", message);
	
	//return 0;
}

void substitution()
{
    
    char msg[] = "INTRODUCTIONTOPROCEDURALPROGRAMMING";
    //char msg[100];
    char key[] = "PROJECT1";
    /*printf("Enter the string");
    scanf("%s\n",&msg); */
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i] = '\0';
 
    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
    
    printf("____SUBSTITUTION METHOD____\n\n");
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s\n\n", newKey);
    printf("____SUBSTITUTION ENCRYPTION____\n");
    printf("\nEncrypted Message: %s\n", encryptedMsg);
    printf("____SUBSTITUTION DECRYPTION____\n");
    printf("\nDecrypted Message: %s", decryptedMsg);
 
	//return 0;

}
int main()
{
    rotation();
    rotation_decrypt();
    substitution();
}





