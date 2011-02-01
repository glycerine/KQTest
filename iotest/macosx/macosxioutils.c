#include "../iotest.h"

/*
 * Function     : kqTimeElapsed
 *
 * Description  : This function calculates the time elapsed.
 *
 * Parameters   :
 *
 * Return Value :
 *                  Retruns the time from gettimeofday function.
 */
int64 kqTimeElapsed()
{
    struct timeval tp;

    debug("%s\n" , __FUNCTION__);

    if (gettimeofday(&tp, (struct timezone *) NULL) == -1) {
            error("gettimeofday failed  %s \n", strerror(errno));
    }
    return (int64)(((int64) (tp.tv_sec)) * 1000000 + (int64) (tp.tv_usec));
}


/*
 * Function     : kqIoOpenInputFile
 *
 * Description  : This function opens the input file.
 *
 * Parameters   :
 *      1. fd       File Desscriptor
 *
 * Return Value :
 *                  Returns SUCCESS if file is opened successfully.
 *                  Returns FAILURE if opening of file fails.
 */
int kqIoOpenInputFile(int *fd)
{
    int fderr;

    debug("%s\n", __FUNCTION__);

    if (strncmp(kqContext.inputFile, "-", 1) != 0) {
        if (kqContext.rarguments.rwflag == IO_DIRECT) {
            *fd = open(kqContext.inputFile, O_RDONLY);
            if (*fd == -1) {
                error("open %s errorcode %s \n", kqContext.inputFile,
                    strerror(errno));
                return FAILURE;
            } else if ((fderr = fcntl(*fd, F_NOCACHE, 1)) == -1) {
                return FAILURE;
            } else {
                return SUCCESS;
            }
        }
        *fd = open(kqContext.inputFile, O_RDONLY);
        if (*fd == -1) {
            error("open %s errorcode %s \n", kqContext.inputFile,
                    strerror(errno));
            return FAILURE;
        } else {
            return SUCCESS;
        }
    } else {
        debug("stdin is the input file\n");
        *fd = 0;
    }
    return SUCCESS;
}


/*
 * Function     : kqIoOpenOutputFile
 *
 * Description  : This function opens the output file.
 *
 * Parameters   :
 *      1. fd       File Desscriptor
 *
 * Return Value :
 *                  Return SUCCESS if file is opened successfully.
 *                  Return FAILURE if opening of file fails.
 */
int kqIoOpenOutputFile(int *fd)
{
    int fderr;

    debug("%s\n", __FUNCTION__);

    if (strncmp(kqContext.outputFile, "-", 1) != 0) {
        if (kqContext.warguments.rwflag == IO_DIRECT) {
            *fd = open(kqContext.outputFile, O_RDWR | O_CREAT, S_IRWXU
                       | S_IRWXG | S_IRWXO);
            if (*fd == -1) {
                error("open %s errocode %s \n", kqContext.outputFile,
                       strerror(errno));
                return FAILURE;
            } else if ((fderr = fcntl(*fd, F_NOCACHE, 1)) == -1) {
                return FAILURE;
            } else {
                return SUCCESS;
            }
        }
        *fd = open(kqContext.outputFile, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG |
                   S_IRWXO);
    } else {
        debug("stdout is the output file\n");
        *fd = 1;
    }
    if (*fd == -1) {
        error("open %s errocode %s \n", kqContext.outputFile, strerror(errno));
        return FAILURE;
    } else {
        return SUCCESS;
    }
}


/*
 * Function     : kqIoMacosxCommonRead
 *
 * Description  : This function reads from the file.
 *
 *  Parameters  :
 *      1. fd       File descriptor.
 *      2. offset   Offset from which read needs to be started.
 *      3. size     iosize
 *      4. buffer   Buffer which will filled after read operation.
 *
 * Return Value :
 *                  Returns SUCCESS if read was successful.
 *                  Returns FAILURE if read failed.
 */
int kqIoCommonRead(int fd, uint64 offset, uint64 size, char *buffer)
{
    uint64 len;

    debug("%s\n", __FUNCTION__);

    if (lseek(fd, offset, SEEK_SET) == -1) {
            error("lseek failed %s \n", strerror(errno));
            exit(ESPIPE);
    }
    len = read(fd, buffer, size);
    if (len != size) {
        error("read file  %-2d error %2"PRIu64" : %s\n", fd, len,
               strerror(errno));
        return FAILURE;
    } else {
        debug("read file  %-2d offset %10"PRIu64" length %10"PRIu64" \n", fd,
              offset, len);
        return SUCCESS;
    }
}


/*
 * Function    : kqIoMacosxCommonWrite
 *
 * Description : This function performs write on the file.
 *
 * Parameters   :
 *      1. fd       File descriptor
 *      2. offset   File offset
 *      3. size     iosize
 *      4. buffer   Buffer, which is filled with pattern for write operation.
 *
 * Return Value :
 *                  Returns SUCCESS if write was successful.
 *                  Returns FAILURE if write failed.
 */
int kqIoCommonWrite(int fd, uint64 offset, uint64 size, char *pattern)
{
    uint64 len;

    debug("%s\n", __FUNCTION__);

    if (lseek(fd, offset, SEEK_SET) == -1) {
            error("lseek failed %s\n", strerror(errno));
            exit(ESPIPE);
    }
    len = write(fd, pattern, size);
    if (len != size) {
        error("write file %2d offset %"PRIu64" length %10"PRIi64"\n", fd,
               offset, size);
        error("write file %2d offset %"PRIu64" length %10"PRIi64" error %s\n",
               fd, offset, len, strerror(errno));
        return FAILURE;
    } else {
        debug("write file %2d offset %"PRIu64" length %10"PRIi64"\n", fd,
               offset, len);
        return SUCCESS;
    }
}


/*
 * Function     :   kqIoGetSectorSize
 *
 * Description  :   On Macsox directio is not dependent on sector alignment.
 *                  So, we just returns SUCCESS from this function.
 *
 * Parameters   :
 *
 * Return Values:   Returns SUCCESS.
 */
int kqIoGetSectorSize(char *File)
{
    return SUCCESS;
}