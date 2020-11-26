// gcc prog.c `pkg-config --cflags glib-2.0` -lglib-2.0

#include <glib.h>
#include <glib/gprintf.h>
#include <gmodule.h>
#include <stdio.h>

enum { N = 80 };
GSList *list = NULL;

gint compare(gconstpointer a, gconstpointer b, gpointer userdata)
{
    GHashTable *hash = (GHashTable *)userdata;
    return g_hash_table_lookup(hash, b) - g_hash_table_lookup(hash, a);
}

void sort(gpointer key, gpointer value, gpointer userdata)
{
    list = g_slist_insert_sorted_with_data(list, key, compare, (GHashTable *)userdata);
}

void print(gpointer data, gpointer userdata)
{
    GHashTable *hash = (GHashTable *)userdata;
    g_printf("%s %ld\n", (char *)data, (long)g_hash_table_lookup(hash, (char *)data));
}

int main(void)
{
    char s[N];
    GHashTable *hash = g_hash_table_new(g_int_hash,  g_str_equal);
    while (fgets(s, N, stdin) != NULL)
    {
        char **tmp, **r;
        tmp = g_strsplit (s, " ", -1);
        for (r = tmp; *r; ++r)
        {
            if (!g_strcmp0(*r, ""))
            {
                continue;
            }
            for (gchar *c = *r; *c != '\0'; ++c)
            {
                if (!g_ascii_isgraph(*c))
                {
                    *c = '\0';
                    break;
                }
            }
            if (g_hash_table_lookup(hash, *r) != NULL)
            {
                g_hash_table_insert(hash, *r, (void *)((long)g_hash_table_lookup(hash, *r) + 1));
            }
            else
            {
                g_hash_table_insert(hash, *r, (void *)(1));
            }
        }
    }
    g_hash_table_foreach(hash, sort, hash);
    g_slist_foreach(list, print, hash);
    g_hash_table_destroy(hash);
    g_slist_free(list);
}
