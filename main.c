#include <gtk/gtk.h>

// 버튼 클릭 시 다이얼로그 띄우기
static void on_button_clicked(GtkButton *button, gpointer user_data) {
    GtkWidget *dialog;
    GtkWindow *parent_window = GTK_WINDOW(user_data);

    dialog = gtk_message_dialog_new(
        parent_window,
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "Hello from GTK3!"
    );

    gtk_window_set_title(GTK_WINDOW(dialog), "GTK3 Dialog");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// 애플리케이션 창 초기화
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK3 Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    button = gtk_button_new_with_label("Show Dialog");
    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
