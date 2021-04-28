#include <kernel/mouse.h>
#include <kernel/system.h>

void mouse_wait(uint8t a_type) {
    uint32t _time_out=100000; //unsigned int
    if(a_type==0) {
        while(_time_out--) {
            if((system_inb(0x64) & 1)==1)
            {
                return;
            }
        }
        return;
    }
    else {
        while(_time_out--) {
            if((system_inb(0x64) & 2)==0) {
                return;
            }
        }
        return;
    }
}

void mouse_write(uint8t a_write) //unsigned char
{
    //Tell the mouse we are sending a command
    mouse_wait(1);
    system_outb(0x64, 0xD4);
    mouse_wait(1);
    //Finally write
    system_outb(0x60, a_write);
}

uint8t mouse_read()
{
    mouse_wait(0);
    return system_inb(0x60);
}

void init_mouse(void)
{
    uint8t _status;
    mouse_wait(1);
    system_outb(0x64, 0xA8);

    //Enable the interrupts
    mouse_wait(1);
    system_outb(0x64, 0x20);
    mouse_wait(0);
    _status=(system_inb(0x60) | 2);
    mouse_wait(1);
    system_outb(0x64, 0x60);
    mouse_wait(1);
    system_outb(0x60, _status);

    // Tell the mouse to use default settings
    mouse_write(0xF6);
    mouse_read();  //Acknowledge

    // Enable the mouse
    mouse_write(0xF4);
    mouse_read();  //Acknowledge
}
