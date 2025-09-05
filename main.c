#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <gtk/gtk.h>
#include "matrix.h"

GtkWidget *window;

static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print("Hello");
  gtk_window_present (GTK_WINDOW (window));
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *box;
  GtkWidget *switcher = gtk_stack_switcher_new();
  GtkWidget *linAlg_button = gtk_button_new_with_label("Linear Algebra");
  GtkWidget *stats_button = gtk_button_new_with_label("Statistics");
  GtkWidget *linAlg_screen = gtk_grid_new();
  GtkWidget *stats_screen = gtk_grid_new();
  GtkWidget *button1 = gtk_button_new_with_label("Hello");
  GtkWidget *button2 = gtk_button_new_with_label("Bye");
  

  GtkWidget *stack = gtk_stack_new();
  gtk_stack_add_titled(GTK_STACK(stack), linAlg_screen, "Linear Algebra","Linear Algebra");
  gtk_stack_add_titled(GTK_STACK(stack), stats_screen, "Statistics","Statistics");
  gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(switcher), GTK_STACK(stack));
  //Making the window
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Plug-N_Chug");
  gtk_window_set_default_size (GTK_WINDOW (window), 1000, 800);

  //Making the box to put our elemnts in
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  //gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  //gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  gtk_window_set_child(GTK_WINDOW(window), box);
  gtk_box_append(GTK_BOX(box), switcher);
  gtk_box_append(GTK_BOX(box), stack);
  

  gtk_grid_attach(GTK_GRID(linAlg_screen),button1,0,0,2,1);
  gtk_grid_attach(GTK_GRID(stats_screen),button2,0,0,2,1);
  
  
  g_signal_connect(linAlg_button,"clicked",G_CALLBACK(print_hello), NULL);

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