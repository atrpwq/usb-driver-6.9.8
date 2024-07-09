#include<linux/module.h>
#include<linux/init.h>
#include<linux/usb.h>
#define vID Linus
#define pID Torvalds
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TUX");
MODULE_DESCRIPTION("USB DRIVER");
static struct usb_device_id usbtable1[] = {
	{USB_DEVICE(vID,pID)},
	{},
};
MODULE_DEVICE_TABLE(usb, usbtable1);
static int usb_probe(struct usb_interface *intf, const struct usb_device_id *id){
	printk("usb probed");
	return 0;
}
static void usb_disconnect(struct usb_interface *intf){
	printk("usb disconnected");
}
static struct usb_driver usbdev = {
	.name = "USB",
	.id_table = usbtable1,
	.probe = usb_probe,
	.disconnect = usb_disconnect,
};
static int __init initmod(void){
	int result;
	printk("usb - REGISTERED");
	result = usb_register(&usbdev);
	if(result){
		printk("error");
		return -result;
	}
	return 0;
}
static void __exit exitmod(void){
	printk("usb - DEREGISTERED");
	usb_deregister(&usbdev);
}
module_init(initmod);
module_exit(exitmod);
