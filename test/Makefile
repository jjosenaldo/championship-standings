# auxiliary variables
PROJECT_DIR=/home/satan/repos/championship-standings
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/test

# variables defined as described in the MakeileWorker.mk
CPPUTEST_HOME=/home/satan/Downloads/cpputest
INCLUDE_DIRS=$(SRC_DIR) $(CPPUTEST_HOME)/include $(TEST_DIR)
SRC_DIRS=$(SRC_DIR)
TEST_SRC_DIRS = $(TEST_DIR) $(TEST_DIR)/addGame $(TEST_DIR)/addGame $(TEST_DIR)/editGame $(TEST_DIR)/removeGame $(TEST_DIR)/getGameResult
TEST_TARGET=out
CPPUTEST_USE_GCOV=Y

# run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# removes some compilation flags
CPPUTEST_WARNINGFLAGS:=$(filter-out -Werror,$(CPPUTEST_WARNINGFLAGS)) # warning as error
CPPUTEST_WARNINGFLAGS:=$(filter-out -Wshadow,$(CPPUTEST_WARNINGFLAGS)) # shadowing of fields

# adds some other warnings
CPPUTEST_WARNINGFLAGS+=-Wunused-result