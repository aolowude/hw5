/*
 * fridge.c 
 * //contains the fridge module code
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include "fridge_data_structures.h"

#define HASH_TABLE_LENGTH 17


	struct hash_table {
    		int size;			/* the size of the table, aka amt. buckets */
    		struct kv_ht_bucket **bucket; 	/* the table elements, aka buckets */
		struct list_head entries; 	/* the bucket content's list_head  */
		struct kkv_entry **entry; 	/* the actual entry int the bucket */ 
//method that creates entries *see HW2 to see how we allocated kernel mem. with kmalloc
	//define list_head entries and kkv_pair and kv_pair

//method that creates buckets *see HW2 to see how we allocated kernel mem. with kmalloc
	//define bucket structures: lock , entries, and count

/*
 * Initialize the Kernel Key-Value store.
 * 
 * Returns 0 on success, and -1 on failure. 
 * The flags parameter is currently unused.
 *
 * The result of initializing twice (without an intervening 
 * kvv_destroy() call) is undefined.
 */
int kkv_init(int flags)
{
	struct kkv_ht_bucket *kv_ht_bucket; //kkv_ht_bucket struct def. in "fridge_data_structures.h"
	
	//create hash table data struct (define size and buckets, call createBucket() method)
	//might not need this: static LIST_HEAD(entries);

	/* create hash table, aka an array of HASH_TABLE_LENGTH buckets */	
	struct hash_table hashtable;
	struct kv_ht_bucket *hashbucket;
	struct kkv_entry *hashentry;

	hashtable = kmalloc(sizeof(bucket_create(size)), GFP_KERNEL);

	/* bucket_create() - function that creates buckets within the hash table */
//kv_ht_bucket *bucket_create(int size) 
		int i, j;
			
		/* allocate kernel memory for each bucket */
		for(i = 0; i < HASH_TABLE_LENGTH; ++i)	
		{
			//init bucket 
			INIT_LIST_HEAD(&(kv_ht_bucket->enteries));
			kv_ht_bucket->count =0;
			spin_lock_init(&(kv_ht_bucket->lock);
	
			//hashbucket = kmalloc(sizeof *hashbucket, GFP_KERNEL);	
			
			//hashbucket->size = i+1;
			//entries.prev = ;
			
			/* allocate kern. memory for each entry */		
				
		}
		return 0;
	
	//create actual has table now
	
}

/*
 * Destroy the Kernel Key-Value store, removing all entries 
 * and deallocating all memories.
 *
 * Returns the number of entries removed on success, and -1 on failure.
 * The flags parameter is currently unused.
 *
 * After calling kkv_destroy(), the Kernel Key-Value store can be 
 * re-initialized by calling kkv_init() again.
 *
 * The result of destroying before initializing is undefined.
 */
int kkv_destroy(int flags)
{
	/* when we destroy, we want to free memory and remove all entries */
	
	/* have a destroyBucket() that has a for loop that goes thru all the entries in each bucket (for all buckets) */
//	void bucket_destroy() 
		struct kkv_ht_entry *c;
		kkv_ht_bucket *in;
		int k, l;		
		for(k = 0; k < HASH_TABLE_LENGTH; ++k)
		{
			if (in != count){
			list_for_each_entry(c, (&(in->enteries)), enteries){
				//kfree
				//list_del
				//kfree
				in->count--;
			}
			kfree(in);
			//delete all buckets
			}
		//	for(l =0; l < HASH_TABLE_LENGTH; ++l)
		//	{
				//delete all entries
		//	}	
		
		free(hashbucket);
		}
	return 0;	
	}		

/*
 * If a key-value pair is found for the given key, the pair is 
 * REMOVED from the Kernel Key-Value store.
 *
 * The value is copied into the buffer pointed to by the "value" parameter,
 * up to max_size - 1 bytes.  If max_size - 1 bytes were copied, 
 * a null character will be put into value[max_size - 1].
 *
 * Returns 0 if a key-value pair was found, removed and returned.
 * Returns -1 with errno set to ENOENT if the key was not found.
 * Returns -1 on other failures, with errno set accordingly.
 * The flags parameter is currently unused.
 *
 * The result of calling kkv_get() before initializing the Kernel Key-Value
 * store is undefined.
 */
int kkv_get(uint32_t key, char *value, size_t max_size, int flags);
{
	//set a pointer to where you are currently and where you are next 
		
	//get the bucket you wanna access from hash table with hash function

	//have a set of nested statement where you check, if bucket has a count, is entry the correct entry, copy_to_user(), and delete that entry
struct kkv_ht_bucket *bucket;
strcut kkv_ht_entry_ *c;
//get hash value 

	int hval = rand() % key;
	bucket = hashtable[hval];
	
	if (bucket->count !=0){
		//not in list
		if ((c.kv_pair).size == max_size)
			return -ENOENT;
		copy_to_user(value, (c->kv_pair).value, max_size);
		//delete the entry now
		return 0;
	}
	return -ENOENT;
}

/* 
 * Insert a new key-value pair. The previous value for the key, if any, is 
 * replaced by the new value.
 *
 * The "size" bytes from the buffer pointed to by the "value" pointer will 
 * be copied.  If the value is a string, make sure that 
 * size == strlen(value) + 1, so that the null character is stored as part
 * of the value.
 *
 * Returns 0 on success, and -1 on failure. 
 * The flags parameter is currently unused.
 *
 * The result of calling kkv_put() before initializing the Kernel 
 * Key-Value store is undefined.
 */
int kkv_put(uint32_t key, char *value, size_t size, int flags);
{
	//define list_head entries
	LIST_HEAD (entries, entry) head;
	struct entries *

	//create pair, entry, set all the values of those things (assign values)
	struct kkv_pair *kvpair;
	struct kkv_entry *kventry;

	value = kvpair->&value;
	key = kvpair->key;
	size = kvpair->size
					
	//create entries
	struct list_head entries = kventry->entries;
	struct kkv_pair kv_pair = kventry->kv_pair;
}


