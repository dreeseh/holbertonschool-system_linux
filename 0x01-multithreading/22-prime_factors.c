#include "multithreading.h"

/**
 * create_task - creates the task
 * @entry: a pointer to the entry function of the task
 * @param: the parameter that will later be passed to the entry function
 * Return: a pointer to the created task structure: task_t*
 */
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *new_task = malloc(sizeof(task_t));

	if (!new_task)
		return (NULL);

	new_task->entry = entry;
	new_task->param = param;
	new_task->status = PENDING;
	new_task->result = NULL;

	return (new_task);
}

/**
 * destroy_task - destroks the task
 * @task: a pointer to the task to destroy
 * Return: is void
 */
void destroy_task(task_t *task)
{
	if (task)
	{
		list_destroy(task->result, free);
		free(task->result);
		free(task);
	}
}

/**
 * exec_tasks - executes the list of tasks
 * @tasks: a pointer to the list of tasks to be executed
 * Return: is void*
 */
void *exec_tasks(list_t const *tasks)
{
	node_t *new_node = NULL;
	task_t *new_task = NULL;
	int i;

	new_node = tasks->head;
	while (new_node)
	{
		new_task = new_node->content;
		if (new_task->status == PENDING)
		{
			new_task->status = STARTED;
			tprintf("[%02d] Started\n", i);
			new_task->result = (void *)(((list_t *(*) (char const *))
					new_task->entry)((char const *) new_task->param));
			tprintf("[%02d] Success\n", i);
			if (new_task->result == NULL)
				new_task->status = FAILURE;
			else
				new_task->status = SUCCESS;
		}
		new_node = new_node->next;
		i++;
	}
	return (NULL);
}
