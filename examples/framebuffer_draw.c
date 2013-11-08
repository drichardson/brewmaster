#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>


int main(int argc, char* argv[])
{
  int fbfd = 0;
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  long int screensize = 0;
  unsigned short *fbp = 0;

  // Open the file for reading and writing
  fbfd = open("/dev/fb1", O_RDWR);
  if (!fbfd) {
    printf("Error: cannot open framebuffer device.\n");
    return(1);
  }
  printf("The framebuffer device was opened successfully.\n");

  // Get fixed screen information
  if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
    printf("Error reading fixed information.\n");
  }

  // Get variable screen information
  if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
    printf("Error reading variable information.\n");
  }
  printf("%dx%d, %d bpp\n", vinfo.xres, vinfo.yres, 
         vinfo.bits_per_pixel );

  // map framebuffer to user memory 
  screensize = finfo.smem_len;

  fbp = (unsigned short*)mmap(0, 
                    screensize, 
                    PROT_READ | PROT_WRITE, 
                    MAP_SHARED, 
                    fbfd, 0);

  if ((int)fbp == -1) {
    printf("Failed to mmap.\n");
  }
  else {
    // draw...
    // just fill upper half of the screen with something
      int y;
      int x;
      for(y = 0; y < vinfo.yres; y++) {
          for(x = 0; x < vinfo.xres; x++) {
              fbp[y*vinfo.xres+x] = ((0xff&0x1F) << 11) | ((0xff&0x3F) << 5) | (0xff&0x1F);
              //fbp[y*vinfo.xres+x] = 0x0000;
          }
      }
    //memset(fbp, 0xaa, screensize/2);
    // and lower half with something else
    //memset(fbp + screensize/2, 0xff, screensize/2);
  }

  // cleanup
  munmap(fbp, screensize);
  close(fbfd);
  return 0;
}
