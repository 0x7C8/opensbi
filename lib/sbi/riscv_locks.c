/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 * Copyright (c) 2021 Christoph Müllner <cmuellner@linux.com>
 */

#include <sbi/riscv_barrier.h>
#include <sbi/riscv_locks.h>

static inline bool spin_lock_unlocked(spinlock_t lock)
{
	return lock.owner == lock.next;
}

bool spin_lock_check(spinlock_t *lock)
{
	RISCV_FENCE(r, rw);
	return !spin_lock_unlocked(*lock);
}

bool spin_trylock(spinlock_t *lock)
{
	// Does not exist
	return l0 == 0;
}

void spin_lock(spinlock_t *lock)
{
	// Does not exist
}

void spin_unlock(spinlock_t *lock)
{
	__smp_store_release(&lock->owner, lock->owner + 1);
}
