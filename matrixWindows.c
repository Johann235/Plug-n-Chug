#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <gtk/gtk.h>
#include "matrix.h"


GtkWidget *text_field;

static void
print_hello (GtkWidget *widget, gpointer   data)
{
  int number = atoi((char *)gtk_editable_get_text(GTK_ENTRY(text_field)));
  printf("%d\n",number);
}