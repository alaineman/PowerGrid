package org.powerbot.game.api;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface Manifest {
	String name();

	String description();

	double version() default 1.0;

	String[] authors();

	String website() default "";

	int topic() default 0;

	boolean vip() default false;

	boolean hidden() default false;

	boolean singleinstance() default false;
}
