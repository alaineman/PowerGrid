/* Copyright (c) 2002, Toby Reyelts
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of Toby Reyelts nor the names of his contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package jace.util;

/**
 * Replica of the ShutdownHook class used by JACE.
 * <p/>
 * It is included in the PowerGrid client to allow JACE
 * to load the PowerGrid client on the ClassPath without needing 
 * the JACE runtime additional to the PowerGrid client itself.
 * <p/>
 * Minor modifications have been made to this class to ensure Thread-safety of
 * this singleton class.
 * <p/>
 * This class should never be used in actual code, the JVM runs this Thread 
 * automatically just before shutting down. Using this class on its own may 
 * result in undefined behavior.
 * <p/>
 * @author Patrick Kramer (modifications), Toby Reyelts (original)
 */
public class ShutdownHook extends Thread {
    
    private static final Object singletonLock = new Object();
    private static volatile ShutdownHook instance;
    
    private static void clearInstance() {
        // This is put in a separate, static method to prevent direct write 
        // from non-static environment to a static field.
        // It is synchronized on an object lock for Thread-safety.
        synchronized (singletonLock) {
            instance = null;
        }
    }
    
    // private constructor prevents external instantiation.
    private ShutdownHook() {}
    
    /**
     * @return the singleton ShutdownHook instance.
     */
    public static ShutdownHook getInstance() {
        synchronized (singletonLock) {
            if (instance == null) {
                instance = new ShutdownHook();
            }
            return instance;
        }
    }
    
    /**
     * Signals to JACE that the JVM is going to shut down.
     */
    @Override
    public void run() {
        signalVMShutdown();
        // We clear the instance to free any leftover memory
        clearInstance();
    }
    
    // native method call acting as a signal.
    private native void signalVMShutdown();
}
