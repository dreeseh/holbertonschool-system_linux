#include "multithreading.h"

/**
 * create_task - creates the task
 * @entry: is a pointer to the entry function of the task
 * @param: the parameter that will later be passed
 * Return: is task_t*
 */
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *new_task;

	new_task = calloc(1, sizeof(task_t));

	new_task->entry = entry;
	new_task->param = param;
	new_task->status = 0;
	pthread_mutex_init(&new_task->lock, NULL);

	return (new_task);
}

/**
 * destroy_task - destroys a task
 * @task: a pointer to the task to destroy
 * Return: is void
 */
void destroy_task(task_t *task)
{
	/**
	if (pthread_mutex_trylock(&task->lock) == 0)
		return;

	if (task->status == SUCCESS || task->status == FAILURE)
	{
		if (task != NULL)
		{
			task->entry = NULL;
			task->param = NULL;
			task->status = PENDING;
			task->result = NULL;
		}
	}
	pthread_mutex_unlock(&task->lock);
	*/
	if (task->result)
	{
		list_destroy((list_t *) task->result, free);
		free((list_t *) task->result);
	}
	free(task);
}

/**
 * exec_tasks - executes the tasks
 * @tasks: list of tasks
 * Return: is void*
 */
void *exec_tasks(list_t const *tasks)
{
	node_t *this_node = NULL;
	task_t *new_task = NULL;
	int id = 0;


	this_node = tasks->head;
	while (this_node != NULL)
	{
		new_task = this_node->content;
		if (pthread_mutex_trylock(&new_task->lock) == 0)
		{
			this_node = this_node->next;
			id++;
			continue;
		}

		if ((new_task->status) == PENDING)
		{
			new_task->status = STARTED;
			tprintf("[%02d] Started\n", id);
			new_task->result = new_task->entry(new_task->param);
			if (new_task->result == NULL)
			{
				new_task->status = FAILURE;
				tprintf("[%02d] Failure\n", id);
			}
			else
			{
				new_task->status = SUCCESS;
				tprintf("[%02d] Success\n", id);
			}
		}
		this_node = this_node->next;
		id++;
	}
	return (NULL);
}
