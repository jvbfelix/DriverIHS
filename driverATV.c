#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Basic Driver PCIHello");
MODULE_AUTHOR("Joao Felix");

//-- param definiton
int parametro = 10; // 10 is the default value
module_param(parametro, int, 0);

//-- Hardware Handles

static void *hexport;  // handle to 32-bit output PIO
static void *inport;   // handle to 16-bit input PIO

//-- Global module registration

static int __init altera_driver_init(void) {
  printk(KERN_ALERT "driverATV: Olá, o driver foi iniciado\n");
  return parametro;
}

static void __exit altera_driver_exit(void) {
  printk(KERN_ALERT "driverATV: Finalizando o driver, valor recebido - %d\n",parametro);
}

module_init(altera_driver_init);
module_exit(altera_driver_exit);
