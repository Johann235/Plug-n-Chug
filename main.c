#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <gtk/gtk.h>
#include "matrix.h"

GtkWidget *text_field;

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  int number = atoi((char *)gtk_editable_get_text(GTK_ENTRY(text_field)));
  printf("%d\n",number);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  
  GtkWidget *box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Plug-N_Chug");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);

  box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  text_field = gtk_entry_new();

  gtk_box_append (GTK_BOX (box), text_field);
  g_signal_connect(text_field, "activate", G_CALLBACK(print_hello), NULL);

  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char * argv[]){
    GtkApplication *app; 
    app = gtk_application_new ("plug.n.chug", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run (G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}